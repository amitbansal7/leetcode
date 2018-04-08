//Runtime: 215 ms
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int res = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 1) {
					if (j == 0 || grid[i][j - 1] == 0) res++;

					if (i == 0 || grid[i - 1][j] == 0)  res++;

					if (j == grid[i].size() - 1 || grid[i][j + 1] == 0)	res ++;

					if (i == grid.size() - 1 || grid[i + 1][j] == 0)	res++;
				}
			}
		}
		return res;
	}
};