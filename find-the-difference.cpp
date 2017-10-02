//Runtime: 3 ms
class Solution {
public:
    char findTheDifference(string s, string t) {
        int look[26];

        for(int i=0;i<26;i++)
            look[i] = 0;

        for(char c:s)
            look[c-'a']++;

        for(char c:t)
        {
            if(look[c-'a'] == 0)
                return c;

            look[c-'a']--;
        }

    }
};
