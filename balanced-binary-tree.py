# Runtime: 77 ms
class Solution(object):
    def solve(self, root):
        if root == None:
            return 0

        l = self.solve(root.left)
        r = self.solve(root.right)

        if l == -1 or r == -1 or abs(l - r) > 1:
            return -1

        return 1 + max(l, r)

    def isBalanced(self, root):
        return self.solve(root) != -1
