//Runtime: 33 ms
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>sc(26, 0);
        vector<int>pc(26, 0);
        vector<int>res;

        for (int i = 0; i < p.size(); i++)
        {
            pc[p[i] - 'a']++;
            sc[s[i] - 'a']++;
        }

        if (pc == sc)
            res.push_back(0);

        for (int i = p.size(); i < s.size(); i++)
        {
            sc[s[i] - 'a']++;
            sc[s[i - p.size()] - 'a']--;

            if (pc == sc)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
