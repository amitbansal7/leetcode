// Runtime: 8 ms
// Memory Usage: 12 MB
class Solution {
public:
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    vector<vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1));
    for (int i = 0; i <= A.size(); i++) {
      for (int j = 0; j <= B.size(); j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = 0;
        } else if (A[i - 1] == B[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[A.size()][B.size()];
  }
};