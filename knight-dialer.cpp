//Runtime: 28 ms
class Solution {
public:

	vector<vector<int>>moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};

	int knightDialer(int N) {
		int mod = (int)(1e9 + 7);

		vector<int> dp(10, 1);
		vector<int> dpt(10, 0);

		for (int h = 0; h < N; h++) {
			for (int i = 0; i <= 9; i++) {
				dpt[i] = 0;
				for (int m : moves[i]) {
					dpt[i] += dp[m];
					dpt[i] %= mod;
				}
			}
			swap(dp, dpt);
		}
		int res = 0;
		for (int a : dpt) {
			res = (res + a) % mod;
		}
		return res;
	}
};