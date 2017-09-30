//Runtime: 3 ms
class Solution {
public:

    void solve(vector<string> &res, string &s, int opn, int cls, int depth, int n)
    {
        if(depth == 2*n)
        {
            res.push_back(s);
            return;
        }

        if(opn < n)
        {
            s.push_back('(');
            solve(res, s, opn+1, cls, depth+1, n);
            s.pop_back();
        }

        if(cls < opn)
        {
            s.push_back(')');
            solve(res, s, opn, cls+1, depth+1, n);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n<1)
            return res;

        string s;
        solve(res, s, 0, 0, 0, n);
        return res;
    }
};
