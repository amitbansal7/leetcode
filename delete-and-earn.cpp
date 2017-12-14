//Runtime: 9 ms
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>count(10001, 0);
        for (int a : nums)
            count[a] += a;

        vector<int> DP(10003);
        for (int i = 10000; i >= 0; i--)
            DP[i] = max(count[i] + DP[i + 2], DP[i + 1]);
        return DP[0];
    }
};
