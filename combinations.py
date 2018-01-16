# Runtime: 262 ms
class Solution(object):

    def solve(self, res, t, c, k, n):
        if len(t) == k:
            res.append(t)
            return
        if k > len(t) + n - c:
            return
        for i in xrange(c, n):
            self.solve(res, t + [i], i + 1, k, n)

    def combine(self, n, k):
        res = []
        t = []

        self.solve(res, t, 1, k, n + 1)
        return res
