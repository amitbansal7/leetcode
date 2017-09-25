//Runtime: 6 ms
//(Learned from editorial)
class Solution {
public:
    int findPaths(int m, int n, int N, int x, int y) {

        int M = 1000000000 + 7;

        vector<vector<int> >DP(m, vector<int>(n,0));
        DP[x][y] = 1;
        int count = 0;

        for(int mv=1;mv<=N;mv++)
        {
            vector<vector<int> >temp(m, vector<int>(n,0));

            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i == m-1)
                        count = (count+DP[i][j])%M;

                    if(j == n-1)
                         count = (count+DP[i][j])%M;

                    if(i == 0)
                         count = (count+DP[i][j])%M;

                    if(j == 0)
                         count = (count+DP[i][j])%M;

                    int a = i>0?DP[i-1][j]:0;
                    int b = i<m-1?DP[i+1][j]:0;
                    int c = j>0?DP[i][j-1]:0;
                    int d = j<n-1?DP[i][j+1]:0;

                    temp[i][j] = ((a+b)%M + (c+d)%M)%M;
                }
            }

            DP = temp;
        }

        return count;
    }
};
