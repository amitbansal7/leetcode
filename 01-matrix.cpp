//Runtime: 225 ms
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int> > DP(r, vector<int>(c,INT_MAX));

        for(int m=0;m<=1;m++)
        {
            for(int i = m?r-1:0;m?i>=0:i<r;m?i--:i++)
            {
                for(int j = m?c-1:0;m?j>=0:j<c;m?j--:j++)
                {
                    if(matrix[i][j] == 0)
                        DP[i][j] = 0;
                    else
                    {
                        int up = i>0?DP[i-1][j]:INT_MAX;
                        int dn = i+1<r?DP[i+1][j]:INT_MAX;
                        int rt = j+1<c?DP[i][j+1]:INT_MAX;
                        int lt = j>0?DP[i][j-1]:INT_MAX;

                        if(up!=INT_MAX || dn != INT_MAX || rt != INT_MAX || lt != INT_MAX)
                            DP[i][j] = 1 + min(min(up,dn),min(rt,lt));
                    }
                }
            }
        }

        return DP;
    }
};
