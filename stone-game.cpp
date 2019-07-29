// Runtime: 28 ms
// Memory Usage: 25.7 MB
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<pair<int, int> > > dp(n, vector<pair<int, int> > (n));

    for (int i = 0; i < n; i++) {
      dp[i][i] = {piles[i], 0};
    }

    for (int l = 2; l <= n; l++) {
      for (int i = 0; i < n - l + 1; i++) {
        int j = i + l - 1;
        int a = piles[i] + dp[i + 1][j].second;
        int b = piles[j] + dp[i][j - 1].second;

        dp[i][j] = a > b ? make_pair(a, dp[i + 1][j].first) : make_pair(b, dp[i][j - 1].first);
      }
    }

    return dp[n - 1][n - 1].first > dp[n - 1][n - 1].second;
  }
};