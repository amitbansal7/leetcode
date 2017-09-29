//Learned from discuss section
//Runtime: 6 ms
class Solution {
public:

    bool isPalindrome(string &s, int l,int h)
    {
        while(l<=h)
            if(s[l++] != s[h--])
                return 0;
        return 1;
    }

    void solve(string &s, int x, vector<string> &temp, vector<vector<string> >&res)
    {
        if(s.size() == x)
        {
            res.push_back(temp);
            return;
        }
        for(int i=x;i<s.size();i++)
        {
            if(isPalindrome(s, x, i))
            {
                temp.push_back(s.substr(x, i-x+1));
                solve(s, i+1, temp, res);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if(s.size() == 0)
            return res;

        vector<string> temp;
        solve(s, 0, temp, res);
        return res;
    }
};
