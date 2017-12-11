//Runtime: 6 ms
class Solution {
public:
    int ans = -1;
    bool found = 0;

    void Binary(int lo, int hi, vector<int>&nums) {
        if (lo > hi || found)
            return;

        int mid = (lo + hi) / 2;
        if (lo == hi) {
            if (mid + 1 <= hi && nums[mid + 1] == nums[mid] || mid - 1 >= 0  && nums[mid] == nums[mid - 1]) {
                return;
            }
            else
                ans = lo;

            return;
        }

        int f = 0;
        if (mid + 1 <= hi && nums[mid + 1] == nums[mid])
            f = 1;
        else if (mid - 1 >= 0  && nums[mid] == nums[mid - 1])
            f = 1;

        if (f) {
            Binary(lo, mid, nums);
            Binary(mid + 1, hi, nums);
        }
        else
        {
            ans = mid;
            found = 1;
        }
    }

    int singleNonDuplicate(vector<int>& nums) {
        Binary(0, nums.size() - 1, nums);
        return nums[ans];
    }
};
