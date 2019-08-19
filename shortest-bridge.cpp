// Runtime: 140 ms
// Memory Usage: 35.7 MB
class Solution {
public:

  vector<vector<int> > dirs = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};
  int isValid(vector<vector<int> > &A, int x, int y) {
    return (x >= 0 && x < A.size() && y >= 0 && y < A[0].size());
  }

  void dfs(vector<vector<int> >&A, int x, int y, queue<pair<pair<int, int>, int> > &q, vector<vector<bool> > &vis) {
    if (!isValid(A, x, y) || A[x][y] != 1) {
      return;
    }
    A[x][y] = 2;
    q.push({{x, y}, 2});
    vis[x][y] = true;
    for (auto a : dirs) {
      dfs(A, x + a[0], y + a[1], q, vis);
    }
  }

  void visitFirstIsland(vector<vector<int> >&A, queue<pair<pair<int, int>, int> > &q, vector<vector<bool> > &vis) {
    for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < A[0].size(); j++) {
        if (A[i][j] == 1) {
          dfs(A, i, j, q, vis);
          return;
        }
      }
    }
  }

  int shortestBridge(vector<vector<int>>& A) {

    pair<int, int> src = { -1, -1};
    vector<vector<bool> > vis(A.size(), vector<bool>(A[0].size(), false));
    queue<pair<pair<int, int>, int> > q;

    visitFirstIsland(A, q, vis);

    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int x = t.first.first;
      int y = t.first.second;
      int color = t.second;

      for (auto a : dirs) {
        int xr = x + a[0];
        int yr = y + a[1];
        if (isValid(A, xr, yr ) && !vis[xr][yr]) {
          if (A[xr][yr] == 1) {
            return color - 2;
          }
          A[xr][yr] = color + 1;
          q.push({{xr, yr}, color + 1});
          vis[xr][yr] = 1;
        }
      }
    }

    return 1;
  }
};