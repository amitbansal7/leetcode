//Runtime: 8 ms
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (A.size() == 1) {
            return A[0][0];
        }
        int res = INT_MAX;
        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                A[i][j] += min(j - 1 >= 0 ? A[i - 1][j - 1] : INT_MAX, min((j + 1 < A.size()) ? A[i - 1][j + 1] : INT_MAX, A[i - 1][j]));

                if (i == A.size() - 1) {
                    res = min(res, A[i][j]);
                }
            }
        }
        return res;
    }
};