//Runtime: 0 ms
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int DP[target+1];
        for(int i=0;i<=target;i++)
            DP[i] = 0;

        sort(nums.begin(), nums.end());
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j] > i)
                    break;

                if(nums[j] == i)
                    DP[i]++;

                DP[i] += DP[i - nums[j]];
            }
        }
        return DP[target];
    }
};
