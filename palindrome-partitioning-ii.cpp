//Runtime: 12 ms
//time complexity = O(n^2)
//Learned from discuss section
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if(len<=1)
            return 0;

        vector<vector<bool> > isPal(len, vector<bool>(len, 0));

        vector<int> cuts(len+1);
        for(int i=0;i<=len;i++)
            cuts[i] = i - 1;

        for(int i=1;i<len;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(s[i] == s[j] && ((i-j)<2 || isPal[j+1][i-1]))
                {
                    isPal[j][i] = 1;
                    cuts[i+1] = min(cuts[i+1], 1 + cuts[j]);
                }
            }
        }
        return cuts[len];
    }
};




//My solution(Not accepted)
//Status: Time Limit Exceeded
// time complexity = O(n^3)
// 28 / 29 test cases passed.
class Solution {
public:

    bool isPalindrome(string &s, int l, int h)
    {
        while(l<=h)
            if(s[l++] != s[h--])
                return 0;
        return 1;
    }

    int minCut(string s) {
        int len = s.size();

        int DP[len][len];

        for(int i=0;i<len;i++)
            DP[i][i] = 0;

        for(int l=2;l<=len;l++)
        {
            for(int i=0;i<len-l+1;i++)
            {
                int j = l+i-1;

                if(isPalindrome(s, i, j))
                    DP[i][j] = 0;

                else
                {
                    DP[i][j] = INT_MAX;
                    for(int k=i;k<j;k++)
                        DP[i][j] = min(DP[i][j], DP[i][k] + DP[k+1][j] + 1);
                }
            }
        }
        return DP[0][len-1];

    }
};
