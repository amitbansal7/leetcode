//Runtime: 43 ms
class Solution {
public:
    int firstUniqChar(string s) {

        pair<int,int> look[26];

        for(pair<int,int> P:look)
        {
            P.first = 0;
            P.second = -1;
        }

        for(int i=0;i<s.size();i++)
        {
            look[s[i]-'a'].first++;
            look[s[i]-'a'].second = i;
        }

        int ans = s.size();

        for(pair<int,int> P:look)
            if(P.first == 1)
                ans = min(ans, P.second);

        if(ans == s.size())
            return -1;
        return ans;
    }
};
