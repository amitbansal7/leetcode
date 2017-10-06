//Runtime: 62 ms
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sz = nums.size();
        return max(nums[sz-1]*nums[sz-2]*nums[sz-3], nums[0]*nums[1]*nums[sz-1]);
    }
};
