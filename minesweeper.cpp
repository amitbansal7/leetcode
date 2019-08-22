// Runtime: 56 ms
// Memory Usage: 19.6 MB
class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    queue<pair<int, int> > q;
    q.push({click[0], click[1]});
    while (!q.empty()) {
      auto t = q.front();
      q.pop();

      int x(t.first), y(t.second);

      if (board[x][y] == 'M') {
        board[x][y] = 'X';
      } else {
        vector<vector<int> > directions = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, { -1, -1}, {1, 1}, { -1, 1}, {1, -1}};
        int mines = 0;
        for (auto dir : directions) {
          int xr = x + dir[0];
          int yr = y + dir[1];

          if (xr >= 0 && yr >= 0 && xr < board.size() && yr < board[0].size()) {
            if (board[xr][yr] == 'X' || board[xr][yr] == 'M') {
              mines++;
            }
          }
        }

        if (mines > 0) {
          board[x][y] = (char)(mines + '0');
        } else {
          board[x][y] = 'B';
          for (auto dir : directions) {
            int xr = x + dir[0];
            int yr = y + dir[1];

            if (xr >= 0 && yr >= 0 && xr < board.size() && yr < board[0].size() && board[xr][yr] == 'E') {
              q.push({xr, yr});
              board[xr][yr] = 'B';
            }
          }
        }
      }
    }
    return board;
  }
};