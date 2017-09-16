//Runtime: 6 ms
// O(n^2) time and space.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int DP[n][n];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                DP[i][j] = 0;

        DP[0][0] = triangle[0][0];

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j == 0)
                    DP[i][j] = triangle[i][j] + DP[i-1][j];

                else if(i == j)
                    DP[i][j] = triangle[i][j] + DP[i-1][j-1];

                else
                    DP[i][j] = triangle[i][j] + min(DP[i-1][j],DP[i-1][j-1]);
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
            ans = min(ans, DP[n-1][i]);

        return ans;
    }
};
