//Runtime: 6 ms
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[idx] < nums[i])
                idx = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i != idx && nums[i] > nums[idx] / 2)
                return -1;
        }

        return idx;
    }
};
