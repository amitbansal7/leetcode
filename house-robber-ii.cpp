//Runtime: 3 ms
class Solution {
public:

    int rob(vector<int>&nums, int l, int hi) {
        int incl = 0;
        int excl = 0;

        for (int i = l; i < hi; i++) {
            int t = incl;
            incl = max(incl, excl + nums[i]);
            excl = t;
        }
        return max(incl, excl);
    }

    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0)
            return 0;
        if (sz == 1)
            return nums[0];

        return max(rob(nums, 0, sz - 1), rob(nums, 1, sz));
    }
};
