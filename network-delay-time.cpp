//Runtime: 59 ms
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int> > > adj(N + 1);
        for (auto a : times) {
            adj[a[0]].push_back(make_pair(a[1], a[2]));
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
        vector<int> dist(N + 1, 0x3f3f3f3f);
        dist[K] = 0;
        pq.push(make_pair(dist[K], K));

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int u = p.second;
            for (auto e : adj[u]) {
                int w = e.second;
                int v = e.first;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        int res = INT_MIN;
        for (int i = 1; i <= N; i++) {
            res = max(res, dist[i]);
        }
        return res == 0x3f3f3f3f ? -1 : res;
    }
};
