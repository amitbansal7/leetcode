// Runtime: 112 ms
// Memory Usage: 19.1 MB
class Solution {
public:
  vector<vector<int> > allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int> > res;

    queue<pair<int, int> > q;
    vector<vector<bool> > vis(R, vector<bool>(C, 0));
    q.push(make_pair(r0, c0));

    while (!q.empty()) {
      pair<int, int> t = q.front();
      q.pop();

      if (!vis[t.first][t.second])
        res.push_back(vector<int> {t.first, t.second});
      else continue;

      vis[t.first][t.second] = 1;

      if (t.first + 1 < R && !vis[t.first + 1][t.second]) {
        q.push(make_pair(t.first + 1, t.second));
      }

      if (t.first - 1 >= 0 && !vis[t.first - 1][t.second]) {
        q.push(make_pair(t.first - 1, t.second));
      }

      if (t.second + 1 < C && !vis[t.first][t.second + 1]) {
        q.push(make_pair(t.first, t.second + 1));
      }

      if (t.second - 1 >= 0 && !vis[t.first][t.second - 1]) {
        q.push(make_pair(t.first, t.second - 1));
      }

    }
    return res;

  }
};