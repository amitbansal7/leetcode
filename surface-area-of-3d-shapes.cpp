//Runtime: 4 ms
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    res += grid[i][j] * 4 + 2;
                }
                if (i) {
                    res -= min(grid[i - 1][j], grid[i][j]) * 2;
                }
                if (j) {
                    res -= min(grid[i][j - 1], grid[i][j]) * 2;
                }
            }
        }
        return res;
    }
};