//Runtime: 56 ms
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        int next = 0;
        for (int a : A) {
            if (a < next) {
                res += next - a;
            }
            next = max(a, next) + 1;
        }
        return res;
    }
};