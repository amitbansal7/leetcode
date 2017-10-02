//Runtime: 9 ms
//Two pointer
class Solution {
public:
    bool isvowel(char c)
    {
        return tolower(c) == 'a'||tolower(c) == 'e'||tolower(c) == 'i'||tolower(c) == 'o'||tolower(c) == 'u';
    }
    string reverseVowels(string s) {
        int l = 0;
        int h = s.size();
        int lc = -1;
        int rc = -1;
        char tlc;
        char trc;
        while(l<=h)
        {
            if(lc == -1 && isvowel(s[l]))
            {
                tlc = s[l];
                lc = l++;
            }

            if(rc == -1 && isvowel(s[h]))
            {
                trc = s[h];
                rc = h--;
            }

            if(lc == -1)
                l++;

            if(rc == -1)
                h--;

            if(lc != -1 && rc != -1)
            {
                s[lc] = trc;
                s[rc] = tlc;
                lc = rc = -1;
            }
        }
        return s;
    }
};

//Runtime: 13 ms
//Using stack
class Solution {
public:
    string reverseVowels(string s) {
        stack<char>S;
        for(char c:s)
            if(tolower(c) == 'a'||tolower(c) == 'e'||tolower(c) == 'i'||tolower(c) == 'o'||tolower(c) == 'u')
                S.push(c);

        for(int i=0;i<s.size();i++)
            if(tolower(s[i]) == 'a'||tolower(s[i]) == 'e'||tolower(s[i]) == 'i'||tolower(s[i]) == 'o'||tolower(s[i]) == 'u')
            {
                swap(s[i], S.top());
                S.pop();
            }

        return s;
    }
};

