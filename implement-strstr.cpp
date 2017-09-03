//Runtime: 6 ms
class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle.size() < 1)
            return 0;

        int n = haystack.size();
        int m = needle.size();

        for(int i=0;i<haystack.size();i++)
        {
            if(haystack[i] == needle[0])
            {
                int t = i;
                int j = 1;
                i++;
                if(m > n-i+1)
                        break;
                while(i<haystack.size())
                {
                    if(haystack[i] != needle[j])
                        break;
                    i++;j++;

                }
                if(j == needle.size())
                    return t;

                i = t;
            }
        }
        return -1;
    }
};
