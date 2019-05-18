// Runtime: 8 ms
// Memory Usage: 8.6 MB
class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int idx = nums.size() - 1;

    while (idx > 0 && nums[idx - 1] >= nums[idx]) {
      idx--;
    }

    int swp = nums.size() - 1;
    int i = idx;
    while (swp > i) {
      swap(nums[i++], nums[swp--]);
    }

    if (idx > 0) {
      int k = idx--;
      while (nums[k] <= nums[idx]) {
        k++;
      }
      swap(nums[k], nums[idx]);
    }
  }
};