//Runtime: 12 ms
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string s = "";
        for (char c : S) {
            if (c != '-') {
                s += toupper(c);
            }
        }

        if (s.size() == 0)
            return "";
        string res = s.substr(0, s.size() % K);
        s = s.substr(s.size() % K);

        for (int i = 0; i < s.size(); i++) {
            if (res.size() > 0 && i % K == 0) {
                res += '-';
            }
            res.push_back(s[i]);
        }
        return res;
    }
};