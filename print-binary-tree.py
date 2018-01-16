# Runtime: 48 ms
class Solution(object):
    def getHeight(self, root):
        if not root:
            return 0

        return 1 + max(self.getHeight(root.left), self.getHeight(root.right))

    def solve(self, root, res, h, lo, hi):
        if not root or lo > hi:
            return

        mid = (lo + hi) / 2
        res[h][mid] = str(root.val)
        self.solve(root.left, res, h + 1, lo, mid)
        self.solve(root.right, res, h + 1, mid + 1, hi)

    def printTree(self, root):
        h = self.getHeight(root)
        res = [['' for _ in range(pow(2, h) - 1)] for _ in range(h)]
        self.solve(root, res, 0, 0, pow(2, h) - 1)
        return res
