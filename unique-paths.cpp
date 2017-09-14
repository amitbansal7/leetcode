//Runtime: 0 ms
class Solution {
public:
    int uniquePaths(int m, int n) {

    int DP[m][n];

    if(m<2||n<2)
        return 1;

    for(int i=0;i<n;i++)
        DP[0][i] = 1;

    for(int i=0;i<m;i++)
        DP[i][0] = 1;

    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            DP[i][j] = DP[i-1][j] + DP[i][j-1];

    return DP[m-1][n-1];


    }
};
