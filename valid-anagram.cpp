//Runtime: 9 ms
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sc(26,0);
        vector<int> tc(26,0);

        for(char a:s)
            sc[a-'a']++;

        for(char a:t)
            tc[a-'a']++;

        for(int i=0;i<26;i++)
            if(tc[i] != sc[i])
                return 0;

        return 1;
    }
};
