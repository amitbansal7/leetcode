// Runtime: 52 ms
// Memory Usage: 15.1 MB
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    if (grid[0][0] || grid[grid.size() - 1][grid[0].size() - 1]) {
      return -1;
    }

    queue<pair<pair<int, int>, int> > q;

    q.push(make_pair(make_pair(0, 0), 0));

    while (!q.empty()) {
      auto t = q.front();
      int d = t.second + 1;
      q.pop();
      int x = t.first.first;
      int y = t.first.second;

      if (x == grid.size() - 1 && y == grid[0].size() - 1) {
        return d;
      }

      for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
          int xt = x + i;
          int yt = y + j;

          if (xt >= 0 && yt >= 0 && xt < grid.size() && yt < grid[0].size() && !grid[xt][yt]) {
            grid[xt][yt] = 1;
            q.push(make_pair(make_pair(xt, yt), d));
          }
        }
      }
    }
    return -1;

  }
};