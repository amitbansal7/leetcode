//Runtime: 116 ms
class Solution {
public:

    bool ans1 = 1;
    bool ans2 = 1;
    void palin(string &s, int l,int h,int f,int dir)
    {
        while(l<=h)
        {
            if(s[l]!=s[h])
            {
                if(f)
                {
                    if(dir)
                        ans1 = 0;
                    else
                        ans2 = 0;
                    return;
                }
                else
                {
                    palin(s, l+1, h, 1,1);
                    palin(s, l, h-1, 1,0);
                    return;
                }
            }
            l++;
            h--;
        }
    }

    bool validPalindrome(string s) {
        palin(s, 0, s.size()-1, 0,1);
        return ans1 | ans2;
    }
};
