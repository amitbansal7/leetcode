//Runtime: 22 ms
class Solution {
public:

    int solve(vector<vector<int> >&G, int i, int j)
    {
        if (i < 0 || j < 0 || i >= G.size() || j >= G[0].size() || !G[i][j])
            return 0;

        G[i][j] = 0;

        return (
                   1 + solve(G, i + 1, j) +
                   solve(G, i - 1, j) +
                   solve(G, i, j + 1) +
                   solve(G, i, j - 1)
               );
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j])
                    ans = max(ans, solve(grid, i, j));
        return ans;
    }
};
