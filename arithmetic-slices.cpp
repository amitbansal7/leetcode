// Runtime: 104 ms
// Memory Usage: 8.8 MB
class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int res = 0;

    for (int l = 3; l <= A.size(); l++) {
      for (int i = 0; i <= A.size() - l; i++) {
        int j = i + l;
        int diff = A[i + 1] - A[i];

        bool yes = true;
        for (int k = i; k < j - 1; k++) {
          if (A[k + 1] - A[k] != diff) {
            yes = false;
            break;
          }
        }
        if (yes) res ++;
      }
    }
    return res;
  }
};

// Runtime: 4 ms
// Memory Usage: 8.8 MB
class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    vector<int> dp(A.size(), 0);
    int res = 0;
    for (int i = 2; i < A.size(); i++) {
      if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
        dp[i] = dp[i - 1] + 1;
        res += dp[i];
      }
    }
    return res;
  }
};