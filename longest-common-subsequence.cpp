// Runtime: 16 ms
// Memory Usage: 14.7 MB
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1));
    for (int i = 0; i <= text1.size(); i++) {
      for (int j = 0; j <= text2.size(); j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = 0;
        } else if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }
    return dp[text1.size()][text2.size()];
  }
};