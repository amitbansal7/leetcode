//Runtime: 6 ms
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxProfit = 0;
		if (prices.size() <= 1)
			return maxProfit;
		int valley = prices[0];
		int peak = prices[0];

		int i = 0;

		while (i < prices.size() - 1)
		{
			while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
				i++;

			valley = prices[i];

			while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
				i++;

			peak = prices[i];
			maxProfit += peak - valley;
		}
		return maxProfit;
	}
};
