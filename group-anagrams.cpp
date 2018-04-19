//Runtime: 35 ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > mp;

        for (string s : strs) {
            string ts = s;
            sort(ts.begin(), ts.end());
            mp[ts].push_back(s);
        }

        vector<vector<string > >res;
        for (auto &m : mp) {
            res.push_back(m.second);
        }
        return res;
    }
};