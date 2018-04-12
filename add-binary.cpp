//Runtime: 4 ms
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int x = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0) + carry;
            res += (x % 2) + '0';
            carry = x / 2;
            i--; j--;
        }
        if (carry != 0) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};