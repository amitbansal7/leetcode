class Solution {
public:
    bool isValid(string s) {

        stack<char>S;

        int n = s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                S.push(s[i]);
            else
            {
                if(S.empty())
                    return 0;
                char c = S.top();
                S.pop();

                if((c == '{' && s[i] != '}')||(c == '[' && s[i] != ']')||(c == '(' && s[i] != ')'))
                    return 0;
            }
        }
        if(!S.empty())
            return 0;

        return 1;
    }
};
