//Runtime: 49 ms
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        if(len<=1)
            return len;

        vector<vector<int> > DP(len, vector<int>(len, 0));

        for(int i=0;i<len;i++)
            DP[i][i] = 1;

        for(int l=2;l<=len;l++)
        {
            for(int i=0;i<len-l+1;i++)
            {
                int j = i+l-1;

                if(s[i]== s[j])
                    DP[i][j] = 2 + DP[i+1][j-1];

                else
                    DP[i][j] = max(DP[i][j-1], DP[i+1][j]);
            }
        }
        return DP[0][len-1];
    }
};
