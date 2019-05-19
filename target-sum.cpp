// Runtime: 4 ms
// Memory Usage: 8.7 MB
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum < S || S < -sum || (sum + S) % 2 == 1)
      return 0;

    int target = (sum + S) >> 1;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int a : nums) {
      for (int s = target; s >= a; s--) {
        dp[s] += dp[s - a];
      }
    }
    return dp[target];
  }
};