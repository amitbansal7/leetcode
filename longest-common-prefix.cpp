//Runtime: 23 ms
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int> mp;
        string res = "";
        for (string s : strs) {
            for (int i = 0; i <= s.size(); i++) {
                string t = s.substr(0, i);
                mp[s.substr(0, i)]++;
                if (mp[t] == strs.size() && t.size() > res.size()) {
                    res = t;
                }
            }
        }

        return res;
    }
};