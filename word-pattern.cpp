//Runtime: 0 ms
class Solution {
public:
    bool wordPattern(string pattern, string str) {

        if(pattern.size()==0 || str.size() == 0)
            return 0;

        map<string, char> M;
        map<char,string> P;
        vector<string> S;
        string t;
        for(char c:str)
        {
            if(c == ' ')
            {
                S.push_back(t);
                t.clear();
            }
            else
                t += c;
        }

        S.push_back(t);

        if(pattern.size()!=S.size())
            return 0;

        for(int i=0;i<pattern.size();i++)
        {
            if(M.find(S[i]) != M.end())
                if(M[S[i]] != pattern[i])
                    return 0;

            if(P.find(pattern[i]) != P.end())
                if(P[pattern[i]] != S[i])
                    return 0;

            M[S[i]] = pattern[i];
            P[pattern[i]] = S[i];
        }
        return 1;
    }
};
