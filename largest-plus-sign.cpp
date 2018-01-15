//Runtime: 679 ms
class Solution {
public:
	bool check(set<int>&mine, int i, int j, int n) {
		return mine.find(n * i + j) != mine.end();
	}

	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
		set<int> mine;

		for (auto a : mines) {
			mine.insert(a[0]*N + a[1]);
		}

		vector<vector<int> > dp(N, vector<int>(N, 0));
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int t = 0;

			for (int j = 0; j < N; j++) {
				t = check(mine, i, j, N) ? 0 : t + 1;
				dp[i][j] = t;
			}
			t = 0;
			for (int j = N - 1; j >= 0; j--) {
				t = check(mine, i, j, N) ? 0 : t + 1;
				dp[i][j] = min(dp[i][j], t);
			}
		}

		for (int j = 0; j < N; j++) {
			int t = 0;

			for (int i = 0; i < N; i++) {
				t = check(mine, i, j, N) ? 0 : t + 1;
				dp[i][j] = min(dp[i][j], t);
			}

			t = 0;
			for (int i = N - 1; i >= 0; i--) {
				t = check(mine, i, j, N) ? 0 : t + 1;
				dp[i][j] = min(dp[i][j], t);
				ans = max(ans, dp[i][j]);
			}
		}

		return ans;
	}
};
