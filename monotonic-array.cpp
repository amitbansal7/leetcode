//Runtime: 64 ms
class Solution {
public:

    bool check(vector<int>&A, bool t) {
        for (int i = 0; i < A.size() - 1; i++) {
            if ((t && A[i] > A[i + 1]) || (!t && A[i] < A[i + 1]))
                return false;
        }
        return true;
    }

    bool isMonotonic(vector<int>& A) {
        return check(A, 1) || check(A, 0);
    }
};