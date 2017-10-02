//Runtime: 12 ms
class Solution {
public:
    bool isPalindrome(string s) {

        int l = 0;
        int h = s.size()-1;

        while(l<=h)
        {
            if((s[l] <= 57 && s[l] >= 48)||(s[l] <= 90 && s[l]>=65)||(s[l]<=122 && s[l]>=97))
            {
                if((s[h] <= 57 && s[h] >= 48)||(s[h] <= 90 && s[h]>=65)||(s[h]<=122 && s[h]>=97))
                {
                    if(tolower(s[l]) != tolower(s[h]))
                        return 0;
                    l++;
                    h--;
                }
                else
                    h--;
            }
            else
                l++;
        }
        return 1;
    }
};
