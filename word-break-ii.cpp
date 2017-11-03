//Runtime: 35 ms
class Solution {
public:

    unordered_map<string, vector<string > >m;

    vector<string> solve(string s, map<string, int> Mp)
    {
        if(m.count(s) > 0)
            return m[s];

        vector<string> words;

        for(int i=1;i<=s.size();i++)
        {
            string str = s.substr(0, i);
            if(Mp.find(str) != Mp.end())
            {
                if(i == s.size())
                    words.push_back(str);
                else
                {
                    string re = s.substr(i);
                    vector<string> remv = solve(re, Mp);
                    for(int j=0;j<remv.size();j++)
                        words.push_back(str + " " + remv[j]);
                }
            }
        }
        m[s] = words;
        return words;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string,int> Mp;
        for(string a:wordDict)
            Mp[a] = 1;

        return solve(s, Mp);
    }
};
