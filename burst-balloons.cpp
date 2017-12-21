//Runtime: 13 ms
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<vector<int> > DP(n, vector<int>(n, 0));

		for (int l = 1; l <= n; l++) {
			for (int i = 0; i <= n - l; i++) {
				int j = i + l - 1;
				for (int k = i; k <= j; k++) {
					int left = 1;
					int right = 1;

					if (i != 0) {
						left = nums[i - 1];
					}
					if (j != n - 1) {
						right = nums[j + 1];
					}

					int leftBurst = 0;
					int rightBurst = 0;

					if (i != k) {
						leftBurst = DP[i][k - 1];
					}

					if (k != j) {
						rightBurst = DP[k + 1][j];
					}

					DP[i][j] = max(DP[i][j], left * right * nums[k] + leftBurst + rightBurst);
				}
			}
		}
		return DP[0][n - 1];
	}
};
