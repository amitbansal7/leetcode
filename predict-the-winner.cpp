//Runtime: 3 ms
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1)
			return 1;
		vector<vector<pair<int, int> > >DP(n, vector<pair<int, int> >(n));

		for (int i = 0; i < n; i++)
			DP[i][i] = make_pair(nums[i], 0);

		for (int l = 2; l <= n; l++)
		{
			for (int i = 0; i < n - l + 1; i++)
			{
				int j = i + l - 1;

				if (nums[i] + DP[i + 1][j].second > nums[j] + DP[i][j - 1].second)
					DP[i][j] = make_pair(nums[i] + DP[i + 1][j].second, DP[i + 1][j].first);
				else
					DP[i][j] = make_pair(nums[j] + DP[i][j - 1].second, DP[i][j - 1].first);
			}
		}

		return DP[0][n - 1].first >= DP[0][n - 1].second;
	}
};
