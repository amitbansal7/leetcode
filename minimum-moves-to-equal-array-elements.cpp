//Runtime: 53 ms
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int mins = nums[0];
        int n = nums.size();

        for(auto a:nums)
        {
            sum+=a;
            mins = min(mins,a);
        }

        return sum - n*mins;
    }
};
