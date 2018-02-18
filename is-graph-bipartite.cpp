//Runtime: 27 ms
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        if (v == 0)  return 1;

        vector<int> adj[v];

        for (int i = 0; i < graph.size(); i++) {
            for (int a : graph[i]) {
                adj[i].push_back(a);
            }
        }

        queue<int> Q;
        vector<bool> vis(v, 0);
        int src = 0;

        vector<int> color(v, -1);

        for (int src = 0; src < v; src++) {
            if (!vis[src]) {
                vis[src] = 1;
                Q.push(src);
                color[src] = 0;

                while (!Q.empty()) {
                    int t = Q.front();
                    Q.pop();

                    for (int a : adj[t]) {
                        if (!vis[a]) {
                            vis[a] = 1;
                            Q.push(a);
                            color[a] = color[t] ? 0 : 1;
                        }
                        else {
                            if (color[a] == color[t])
                                return 0;
                        }
                    }
                }
            }
        }

        for (int a : vis)
            if (a == 0)
                return 0;

        return 1;
    }
};
