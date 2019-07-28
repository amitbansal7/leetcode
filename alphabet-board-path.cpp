// Runtime: 4 ms
// Memory Usage: 8.6 MB
class Solution {
public:
  string alphabetBoardPath(string target) {
    vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    map<char, pair<int, int> > mp;

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        mp[board[i][j]] = {i, j};
      }
    }

    int x(0), y(0);
    string res = "";

    for (char a : target) {
      int xi = mp[a].first;
      int yi = mp[a].second;

      if (y > yi) {
        for (int i = 0; i < abs(y - yi); i++) res += "L";
      }

      if (x > xi) {
        for (int i = 0; i < abs(x - xi); i++) res += "U";
      }

      if (y < yi) {
        for (int i = 0; i < abs(y - yi); i++) res += "R";
      }

      if (x < xi) {
        for (int i = 0; i < abs(x - xi); i++) res += "D";
      }

      x = xi;
      y = yi;
      res += "!";
    }
    return res;
  }
};