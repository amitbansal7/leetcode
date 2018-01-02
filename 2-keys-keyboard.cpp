//Runtime: 39 ms
class Solution {
public:
	int minSteps(int n) {
		vector<int>DP(n + 1, 0);

		for (int i = 2; i <= n; i++) {
			DP[i] = i;
			for (int j = i - 1; j > 1; j--) {
				if (i % j == 0) {
					DP[i] = DP[j] + (i / j);
					break;
				}
			}
		}

		return DP[n];
	}
};
