// Runtime: 8 ms
// Memory Usage: 8.8 MB
class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (int a : stones) {
      sum += a;
    }

    vector<vector<bool > >dp(stones.size(), vector<bool>(sum));
    for (int i = 0; i < stones.size(); i++) {
      dp[i][0] = 1;
    }

    for (int i = 0; i < stones.size(); i++) {
      for (int j = 1; j <= sum; j++) {
        if (stones[i] > j) {
          dp[i][j] = i < 1 ? 0 : dp[i - 1][j];
        } else if (stones[i] == j) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = i < 1 ? 0 : (dp[i - 1][j - stones[i]] || dp[i - 1][j]);
        }
      }
    }

    for (int i = sum / 2; i >= 0; i--) {
      if (dp[stones.size() - 1][i]) {
        return sum - 2 * i;
      }
    }
    return -1;
  }
};