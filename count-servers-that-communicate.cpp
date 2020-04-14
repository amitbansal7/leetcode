// Runtime: 56 ms
// Memory Usage: 15.1 MB
class Solution {
public:
  int countServers(vector<vector<int>>& grid) {
    vector<int> row(grid.size(), 0);
    vector<int> col(grid[0].size(), 0);

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j]) {
          row[i]++;
          col[j]++;
        }
      }
    }
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] && (row[i] > 1 || col[j] > 1)) {
          res++;
        }
      }
    }
    return res;
  }
};