//Runtime: 39 ms
class Solution {
public:

    bool dfs(vector<int> &nums, int idx, vector<int>&temp, int tar) {
        if (idx >= nums.size()) {
            for (int a : temp) {
                if (a != tar)
                    return false;
            }
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (temp[i] + nums[idx] <= tar) {
                temp[i] += nums[idx];
                if (dfs(nums, idx + 1, temp, tar))
                    return true;
                temp[i] -= nums[idx];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for (int a : nums) {
            sum += a;
        }
        if (sum == 0 || sum % 4 != 0)
            return false;

        int tar = sum / 4;
        vector<int> temp(4, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(nums, 0, temp, tar);
    }
};
