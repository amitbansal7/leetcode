// Runtime: 88 ms
// Memory Usage: 24 MB
class Solution {
public:
  bool res = true;
  void dfs(vector<vector<int> > &adj, vector<bool> &vis, int src) {
    for (int a : adj[src]) {
      if (vis[a]) {
        res = false;
        return;
      }
      vis[a] = 1;
      dfs(adj, vis, a);
    }
  }

  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector<vector<int> > adj(n);
    for (int i = 0; i < n; i++) {
      if (leftChild[i] != -1) {
        adj[i].push_back(leftChild[i]);
      }
      if (rightChild[i] != -1) {
        adj[i].push_back(rightChild[i]);
      }
    }
    vector<bool> vis(n, false);
    int comp = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        vis[i] = 1;
        dfs(adj, vis, i);
        comp++;
        if (!res) return false;
      }
    }
    return comp <= 1;

  }
};