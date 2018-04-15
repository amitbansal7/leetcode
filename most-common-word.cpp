//Runtime: 7 ms
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> ban;
        for (string s : banned) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            ban.insert(s);
        }
        int resi = 0;
        string res;
        map<string, int> mp;
        string t;
        for (char c : paragraph) {
            if (c == ' ') {
                if (ban.find(t) == ban.end()) {
                    mp[t]++;
                    if (resi < mp[t]) {
                        resi = mp[t];
                        res = t;
                    }
                }
                t.clear();
            } else if (!ispunct(c)) {
                t += tolower(c);
            }
        }
        if (ban.find(t) == ban.end()) {
            mp[t]++;

            if (resi < mp[t]) {
                resi = mp[t];
                res = t;
            }
        }

        return res;
    }
};