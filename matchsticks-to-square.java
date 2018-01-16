//Runtime: 40 ms
class Solution {

    private boolean dfs(int[] nums, int idx, int[] temp, int tar) {
        if (idx >= nums.length) {
            for (int a : temp) {
                if (a != tar)
                    return false;
            }
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (temp[i] + nums[idx] <= tar) {
                temp[i] += nums[idx];
                if (dfs(nums, idx + 1, temp, tar)) return true;
                temp[i] -= nums[idx];
            }
        }
        return false;
    }

    public boolean makesquare(int[] nums) {
        if (nums == null)
            return false;

        int sum = 0;
        for (int a : nums) {
            sum += a;
        }
        if (sum == 0 || sum % 4 != 0)
            return false;

        Arrays.sort(nums);
        int i = 0, j = nums.length - 1;
        while (i < j) {
            int t = nums[i];
            nums[i++] = nums[j];
            nums[j--] = t;
        }

        return dfs(nums, 0, new int[4], sum / 4);
    }
}
