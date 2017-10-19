//My solution
//Runtime: 19 ms
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return 0;

        string temp = t;
        map<char,char> M;
        map<char,char>P;

        for(int i=0;i<s.size();i++)
        {
            if(M.find(s[i]) != M.end() && M[s[i]] != t[i])
                return 0;

            if(P.find(t[i]) != P.end() && P[t[i]] != s[i])
                return 0;

            P[t[i]] = s[i];
            M[s[i]] = t[i];
        }


        for(int i=0;i<t.size();i++)
        {
            if(M.find(s[i]) == M.end())
                return 0;
            t[i] = M[s[i]];
        }
        return t == temp;
    }
};

//Better solution
//Runtime: 9 ms
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>M(256, 0);

        for(int i=0;i<s.size();i++)
        {
            if(M[s[i]] == 0)
                M[s[i]] = t[i];
            else if(M[s[i]] != t[i])
                return 0;
        }

        vector<int>P(256,0);
        for(int i=0;i<t.size();i++)
        {
            if(P[t[i]] == 0)
                P[t[i]] = s[i];
            else if(P[t[i]] != s[i])
                return 0;
        }
        return 1;
    }
};
