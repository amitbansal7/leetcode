# Runtime: 116 ms
class Solution(object):

    def solve(self, count, t, res, mx):
        if len(t) == mx:
            res.append(t)
            return

        for k, v in count.items():
            if v > 0:
                count[k] = count[k] - 1
                self.solve(count, t + [k], res, mx)
                count[k] = count[k] + 1

    def permuteUnique(self, nums):
        count = {a: 0 for a in set(nums)}

        for a in nums:
            count[a] = count[a] + 1

        t = []
        res = []
        self.solve(count, t, res, len(nums))
        return res
