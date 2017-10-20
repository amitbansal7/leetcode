//Runtime: 16 ms
class Solution {
public:
    map<string, multiset<string> > graph;
    vector<string> res;

    void DFS(string src)
    {
        while(graph[src].size()>0)
        {
            string next = *graph[src].begin();
            graph[src].erase(graph[src].begin());
            DFS(next);
        }
        res.push_back(src);
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(pair<string, string> P: tickets)
            graph[P.first].insert(P.second);

        DFS("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
