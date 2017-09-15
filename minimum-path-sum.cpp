//Runtime: 6 ms
class Solution {
public:

    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int DP[m][n];

        DP[0][0] = grid[0][0];

        for(int i=1;i<m;i++)
            DP[i][0] = grid[i][0] + DP[i-1][0];

        for(int i=1;i<n;i++)
            DP[0][i] = grid[0][i] + DP[0][i-1];

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                    DP[i][j] = grid[i][j] + min(DP[i-1][j], DP[i][j-1]);

        return DP[m-1][n-1];
    }
};
