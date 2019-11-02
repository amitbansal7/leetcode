// Runtime: 52 ms
// Memory Usage: 20.3 MB
class Solution {
public:
  int mdepth = 0;
  int node = 0;

  void dfs(vector<vector<int> > &adj, vector<bool> &vis, int src, int depth) {
    vis[src] = true;
    for (int a : adj[src]) {
      if (!vis[a]) {
        dfs(adj, vis, a, depth + 1);
      }
    }
    if (depth > mdepth) {
      mdepth = depth;
      node = src;
    }
  }

  int treeDiameter(vector<vector<int>>& edges) {
    vector<vector<int> > adj(edges.size() + 1, vector<int>());
    for (auto a : edges) {
      adj[a[0]].push_back(a[1]);
      adj[a[1]].push_back(a[0]);
    }
    vector<bool> vis(edges.size() + 1, 0);
    dfs(adj, vis, 0, 0);
    vis = vector<bool>(edges.size() + 1, 0);
    dfs(adj, vis, node, 0);
    return mdepth;
  }
};