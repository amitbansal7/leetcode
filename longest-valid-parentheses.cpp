// Runtime: 4 ms
// Memory Usage: 9.6 MB
class Solution {
public:
  int longestValidParentheses(string s) {
    vector<int> dp(s.size(), 0);
    int res = 0;

    for (int i = 1; i < s.size(); i++) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i] = ((i - 2 >= 0) ? dp[i - 2] : 0) + 2;
        } else if (s[i - 1] == ')' && i - 1 - dp[i - 1] >= 0 && s[i - dp[i - 1] - 1] == '(') {
          dp[i] = 2 + dp[i - 1] + ((i - 2 - dp[i - 1]) >= 0 ? dp[i - 2 - dp[i - 1]] : 0);
        }
      }
      res = max(res, dp[i]);
    }

    return res;
  }
};