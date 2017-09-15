//Runtime: 3 ms
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int DP[m][n];

        int fi,fj;
        fi = 0;
        fj = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j] || ((fi && !i) || (fj && !j)) )
                {
                    DP[i][j] = 0;
                    if(!i)
                        fi = 1;
                    if(!j)
                        fj = 1;
                }

                else if(!i || !j)
                    DP[i][j] = 1;
                else
                    DP[i][j] = DP[i-1][j] + DP[i][j-1];
            }
        }

        return DP[m-1][n-1];


    }
};
