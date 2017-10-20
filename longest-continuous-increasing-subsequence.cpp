//Runtime: 13 ms
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int c = 1;

        if(nums.size() <=1)
            return nums.size();
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] < nums[i+1])
                c++;
            else
            {
                ans = max(ans, c);
                c = 1;
            }
        }
        return max(ans,c);
    }
};
