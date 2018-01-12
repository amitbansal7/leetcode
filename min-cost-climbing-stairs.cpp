//Runtime: 12 ms
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int>dp(cost.size());
		dp[0] = cost[0];
		dp[1] = cost[1];

		for (int i = 2; i < cost.size() - 1; i++) {
			dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
		}

		return min(dp[cost.size() - 2], cost[cost.size() - 1] + dp[cost.size() - 3]);
	}
};
