// Runtime: 4 ms
// Memory Usage: 9.2 MB
class Solution {
public:

  int orangesRotting(vector<vector<int>>& grid) {
    int one = 0;
    queue<pair<int, pair<int, int> > > q;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 2) {
          q.push(make_pair(0, make_pair(i, j)));
        }
        if (grid[i][j] == 1) one++;
      }
    }

    if (!one) return 0;
    if (q.empty()) return -1;

    int res = 0;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int d = t.first;
      res = max(res, d++);
      int x = t.second.first;
      int y = t.second.second;

      if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
        grid[x + 1][y] = 2;
        one--;
        q.push(make_pair(d, make_pair(x + 1, y)));
      }

      if (x - 1 >= 0 && grid[x - 1][y] == 1) {
        grid[x - 1][y] = 2;
        one--;
        q.push(make_pair(d, make_pair(x - 1, y)));
      }

      if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
        grid[x][y + 1] = 2;
        one--;
        q.push(make_pair(d, make_pair(x, y + 1)));
      }

      if (y - 1 >= 0 && grid[x][y - 1] == 1) {
        grid[x][y - 1] = 2;
        one--;
        q.push(make_pair(d, make_pair(x, y - 1)));
      }

    }
    if (one) return -1;
    return res;
  }
};