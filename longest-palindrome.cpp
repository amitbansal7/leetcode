// Runtime: 6 ms
class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mymap;

        for(auto it:s)
            mymap[it]++;

        int p = 0;
        map<char,int> ::iterator it;
        int f = 0;
        for(it=mymap.begin();it!=mymap.end();it++)
        {
           if(((it->second)%2 == 1 || it->second == 1) && !f)
                f = 1;
           if(it->second >= 2)
                 p += (it->second)/2;
        }

        p*=2;
        if(f) p++;
        return p;
    }
};
