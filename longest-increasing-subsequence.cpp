//Runtime: 29 ms
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();

        if(len <=1)
            return len;


        int DP[len];
        for(int i=0;i<len;i++)
            DP[i] = 1;

        int ans = INT_MIN;

        for(int i=1;i<len;i++)
            for(int j=0;j<i;j++)
                if(nums[j] < nums[i])
                    DP[i] = max(DP[i], DP[j]+1);


        for(int i=0;i<len;i++)
            ans = max(ans, DP[i]);


        return ans;
    }
};
