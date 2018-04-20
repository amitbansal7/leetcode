//Runtime: 13 ms
class Solution {
public:
	int countSubstrings(string s) {
		vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), 0));
		int n = s.size();
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (s[i] == s[j] && (i - j < 3 || dp[i - 1][j + 1])) {
					dp[i][j] = 1;
					res++;
				}
			}
		}
		return res;
	}
};