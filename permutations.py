# Runtime: 66 ms
class Solution(object):

    def solve(self, nums, cache, res, t):
        if len(nums) == len(t):
            res.append(t)
            return

        for i in range(len(nums)):
            if not cache[i]:
                cache[i] = True
                self.solve(nums, cache, res, t + [nums[i]])
                cache[i] = False

    def permute(self, nums):
        res = []
        cache = [0 for i in range(len(nums))]
        t = []
        self.solve(nums, cache, res, t)
        return res
