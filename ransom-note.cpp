//Runtime: 22 ms
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int look[123];

        for(int i=97;i<=122;i++)
            look[i] = 0;

        for(char c:magazine)
            look[c]++;

        for(char c:ransomNote)
        {
            if(look[c])
                look[c]--;
            else
                return 0;
        }
        return 1;
    }
};
