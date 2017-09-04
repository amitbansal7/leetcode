//Runtime: 9 ms
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() <= 1)
            return 0;

        int minp = prices[0];
        int maxp = INT_MIN;

        for(int i=1;i<prices.size();i++)
        {
            minp = min(minp, prices[i]);
            maxp = max(maxp, prices[i] - minp);
        }

        return maxp;

    }
};
