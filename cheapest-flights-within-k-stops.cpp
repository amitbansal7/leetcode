//Runtime: 10 ms
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int> > dist(n, make_pair(INT_MAX, 0));
        vector<pair<int, int> > adj[n];

        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
        dist[src] = make_pair(0, 0);

        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int t = pq.top().second;
            pq.pop();
            if (dst == t)
                break;
            for (auto a : adj[t]) {
                if (dist[a.first].first > dist[t].first + a.second && dist[a.first].second <= K) {
                    dist[a.first] = make_pair(dist[t].first + a.second, dist[t].second + 1);
                    pq.push(make_pair(dist[a.first].first, a.first));
                }
            }
        }

        if (dist[dst].first == INT_MAX || dist[dst].second - 1 > K)
            return -1;
        return dist[dst].first;
    }
};
