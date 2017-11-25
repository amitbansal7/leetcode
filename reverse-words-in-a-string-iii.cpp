//Runtime: 23 ms
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string t;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                t += s[i];
            else
            {
                reverse(t.begin(), t.end());
                res += t + ' ';
                t.clear();
            }
        }
        if (t.size() >= 1)
        {
            reverse(t.begin(), t.end());
            res += t;
        }
        return res;
    }
};
