//Runtime: 0 ms
class Solution {
public:

  int solve(vector<vector<int> > &grid, int x, int y, int s, int ts) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) {
      return 0;
    }

    if (grid[x][y] == 2) {
      return s == ts ? 1 : 0;
    }

    grid[x][y] = -1;

    int paths = solve(grid, x + 1, y, s + 1, ts)
                + solve(grid, x - 1, y, s + 1, ts)
                + solve(grid, x, y + 1, s + 1, ts)
                + solve(grid, x, y - 1, s + 1, ts);

    grid[x][y] = 0;
    return paths;

  }

  int uniquePathsIII(vector<vector<int>>& grid) {
    // vector<vector<int> >dp(grid.size(), vector<int>(grid[0].size(), 0));

    int x, y;
    int ts = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          x = i;
          y = j;
        }
        if (grid[i][j] != -1) ts++;
      }
    }

    return solve(grid, x, y, 1, ts);

  }
};