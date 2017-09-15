// Runtime: 9 ms
class Solution {
public:
    int minDistance(string word1, string word2) {

        int l1 = word1.size();
        int l2 = word2.size();

        int DP[l1+1][l2+1];

        for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
            {
                if(i==0)
                    DP[i][j] = j;
                else if(j == 0)
                    DP[i][j] = i;

                else if(word1[i-1] == word2[j-1])
                    DP[i][j] = DP[i-1][j-1];

                else
                    DP[i][j] = 1 + min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1]));
            }
        }

        return DP[l1][l2];

    }
};
