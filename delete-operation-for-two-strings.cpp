//Runtime: 32 ms
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int> > DP(m+1, vector<int>(n+1, 0));

        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i == 0)
                    DP[i][j] = j;
                else if(j == 0)
                    DP[i][j] = i;

                else if(word1[i-1] == word2[j-1])
                    DP[i][j] = DP[i-1][j-1];
                else
                    DP[i][j] = 1 + min(DP[i-1][j], DP[i][j-1]);
            }
        }
        return DP[m][n];
    }
};
