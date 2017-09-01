// Runtime: 345 ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxl = 0;

        int prevn = 0;
        for(int i=0;i<s.length();i++)
        {
            set<char> myset;
            myset.insert(s[i]);
            int prev = 1;
            int f = 1;
            for(int j=i+1;j<s.length();j++)
            {
                myset.insert(s[j]);
                if(myset.size() == prev)
                {
                    maxl = max(maxl, prev);
                    f=0;
                    break;
                }

                prev++;
            }
           if(f) maxl = max(maxl, prev);

        }
        return maxl;
    }
};


// // Runtime: 29 ms
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {

//         int index[128]={};
//         int maxl = 0;
//         int n = s.length();
//         for(int i=0,j=0;j<n;j++)
//         {
//             const char chk = s[j];
//             i = max(index[chk], i);
//             maxl = max(maxl, j-i+1);
//             index[chk] = j+1;
//         }
//         return maxl;
//     }
// };
