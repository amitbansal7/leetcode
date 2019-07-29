// Runtime: 0 ms
// Memory Usage: 16.9 MB
class Solution {
public:

  bool valid(char c) {
    return c != '0';
  }
  bool valid(char a, char b) {
    return a  == '1' || (a == '2' && b <= '6');
  }

  int solve(string s, int i, vector<int> &dp) {
    if (i == s.size()) {
      return 1;
    }
    if (dp[i] != -1)
      return dp[i];

    int res = 0;
    if (valid(s[i]))
      res = solve(s, i + 1, dp);

    if (i + 1 < s.size() && valid(s[i], s[i + 1])) {
      res += solve(s, i + 2, dp);
    }

    return dp[i] = res;
  }

  int numDecodings(string s) {
    if (s.size() == 0 || s[0] == '0') {
      return 0;
    }

    vector<int> dp(s.size() + 1, -1);

    return solve(s, 0, dp);
  }
};