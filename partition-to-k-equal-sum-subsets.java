//Runtime: 19 ms
class Solution {

    public boolean solve(int[] groups, int idx, int[] nums, int target) {
        if (idx < 0)
            return true;

        int num = nums[idx];
        for (int i = 0; i < groups.length; i++) {
            if (groups[i] + num <= target) {
                groups[i] += num;
                if (solve(groups, idx - 1, nums, target))
                    return true;
                groups[i] -= num;
            }
            if (groups[i] == 0) break;
        }
        return false;
    }

    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for (int a : nums) {
            sum += a;
        }

        if (sum % k > 0)  return false;
        int target = sum / k;
        Arrays.sort(nums);
        if (nums[nums.length - 1] > target)
            return false;

        int idx = nums.length - 1;
        while (idx >= 0 && nums[idx] == target) {
            idx--;
            k--;
        }
        return solve(new int[k], idx, nums, target);
    }
}
