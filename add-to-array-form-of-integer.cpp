//Runtime: 144 ms
//Memory Usage: 11.8 MB
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int r = 0;
        vector<int> res;
        vector<int> B;

        int i = A.size() - 1;
        while (i >= 0 || K) {
            int x = r + ((i >= 0) ? A[i--] : 0) + ((K > 0) ? K % 10 : 0);
            K /= 10;
            res.push_back(x % 10);
            r = x / 10;
        }

        if (r) {
            res.push_back(r);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};