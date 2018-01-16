# Runtime: 2573 ms
class Solution(object):
    def dfs(self, nums, idx, temp, target):
        if idx >= len(nums):
            for a in temp:
                if a != target:
                    return False

            return True

        for i in range(4):
            if temp[i] + nums[idx] <= target:
                temp[i] += nums[idx]
                if self.dfs(nums, idx + 1, temp, target):
                    return True

                temp[i] -= nums[idx]

        return False

    def makesquare(self, nums):
        total = sum(nums)
        target = int(total / 4)
        if total == 0 or total % 4 != 0:
            return False
        nums.sort(reverse=True)
        return self.dfs(nums, 0, [0 for _ in range(4)], target)
