//Runtime: 75 ms O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        bool lookup[len][len];
        int ansi,maxl;
        ansi = 0;
        maxl = 1;
        memset(lookup,0,sizeof(lookup));
        for(int i=0;i<len;i++)
            lookup[i][i] = 1;

        for(int i=0;i<len-1;i++)
            if(s[i] == s[i+1])
            {
                lookup[i][i+1] = 1;
                ansi = i;
                maxl = 2;
            }

        for(int l=3;l<=len;l++)
        {
            for(int i=0;i<len-l+1;i++)
            {
                int j = i +l-1;
                if(lookup[i+1][j-1] && s[i] == s[j])
                {
                    lookup[i][j] = 1;
                    if(l > maxl)
                    {
                        ansi = i;
                        maxl = l;
                    }
                }
            }
        }
        string ans;
        for(int j=ansi;j<maxl+ansi;j++)
            ans.push_back(s[j]);

        return ans;
    }
};
