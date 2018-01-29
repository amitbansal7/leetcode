//Runtime: 54 ms
class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

		for (string s : strs) {
			int one = 0, zero = 0;

			for (char c : s) {
				if (c == '1') one++; else zero++;
			}

			for (int i = m; i >= zero; i--) {
				for (int j = n; j >= one; j--) {
					dp[i][j] = max(dp[i][j], 1 + dp[i - zero][j - one]);
				}
			}
		}
		return dp[m][n];
	}
};
