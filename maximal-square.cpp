//Brute Force
//Runtime: 12 ms
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = rows>0?matrix[0].size():0;

        int maxl = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j] == '1')
                {
                    int len = 1;
                    bool f = 1;

                    while(i+len < rows && j+len<cols && f)
                    {
                        for(int k=j;k<=len+j;k++)
                            if(matrix[i+len][k] =='0')
                            {
                                f = 0;
                                break;
                            }

                        for(int k=i;k<=len+i;k++)
                        {
                            if(matrix[k][j+len] == '0')
                            {
                                f = 0;
                                break;
                            }
                        }

                        if(f)
                            len++;
                    }

                    maxl = max(maxl, len);
                }
            }
        }

        return maxl*maxl;
    }
};


//Optimal solution - DP
//Runtime: 6 ms
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = rows>0?matrix[0].size():0;
        int DP[rows+1][cols+1];
        int ans = 0;

        for(int i=0;i<=rows;i++)
        {
            for(int j=0;j<=cols;j++)
            {
                if(!i || !j || matrix[i-1][j-1] == '0')
                    DP[i][j] = 0;

                else if(matrix[i-1][j-1] == '1')
                {
                    DP[i][j] = min(min(DP[i-1][j], DP[i][j-1]), DP[i-1][j-1]) + 1;
                    ans = max(ans, DP[i][j]);
                }
            }
        }
        return ans*ans;
    }
};
