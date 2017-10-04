//Runtime: 9 ms
class Solution {
public:
    string reverseString(string s) {
        int l=0;
        int h = s.size()-1;

        while(l<h)
            swap(s[l++], s[h--]);

        return s;
    }
};
