//Runtime: 9 ms
class Solution {
public:

    void solve(vector<string> &res, string t, string s, int i) {
        if (i >= s.size()) {
            res.push_back(t);
            return;
        }
        if (isdigit(s[i])) {
            solve(res, t + s[i], s, i + 1);
            return;
        }
        char l = tolower(s[i]);
        char u = toupper(s[i]);
        solve(res, t + l, s, i + 1);
        solve(res, t + u, s, i + 1);
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string t = "";
        solve(res, t, S, 0);
        return res;
    }
};
