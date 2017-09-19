//Runtime: 32 ms
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int>DP(amount+1,-1);
        DP[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            int ans = INT_MAX;
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j] >= 0 && DP[i-coins[j]] != -1)
                    ans = min(ans, DP[i-coins[j]]+1);
            }

            if(ans != INT_MAX)
                DP[i] = ans;
        }
        return DP[amount];
    }
};
