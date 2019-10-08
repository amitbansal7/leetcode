// Runtime: 56 ms
// Memory Usage: 8.7 MB
class Solution {
public:

  int dfs(vector<vector<int> >&grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
      return 0;
    }

    int temp = grid[i][j];
    grid[i][j] = 0;
    int res = 0;
    res = max(res, dfs(grid, i + 1, j));
    res = max(res, dfs(grid, i - 1, j));
    res = max(res, dfs(grid, i, j + 1));
    res = max(res, dfs(grid, i, j - 1));
    grid[i][j] = temp;
    return res + temp;
  }

  int getMaximumGold(vector<vector<int>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        res = max(res, dfs(grid, i, j));
      }
    }
    return res;
  }
};