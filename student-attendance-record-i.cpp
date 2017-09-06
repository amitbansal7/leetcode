//Runtime: 3 ms
class Solution {
public:
    bool checkRecord(string s) {
        int ap = 0;
        int l = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'A')
                ap++;
            else if(s[i] == 'L')
            {
                while(s[i] == 'L')
                {
                    l++;
                    i++;
                }
                if(l>2)
                    break;
                i--;
                l = 0;
            }
        }
        if(ap > 1 || l>2)
            return 0;

        return 1;
    }
};
