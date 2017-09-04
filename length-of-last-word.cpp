//Runtime: 3 ms
class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.size();
        if(l == 0)
            return 0;
        int lsp = -1;
        int f = 1;
        int lstw = 0;
        for(int i=0;i<l;i++)
        {
            if(s[i] == ' ')
                f = 1;
            else
            {
                if(f)
                    lstw = i;
                f = 0;
            }
        }
        int ans = 0;
        for(int i=lstw;i<l;i++)
        {
            if(s[i] ==' ')
                break;
            ans++;
        }
        return ans;
    }
};
