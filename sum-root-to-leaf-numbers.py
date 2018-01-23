# Runtime: 48 ms


class Solution(object):
    ans = 0

    def solve(self, root, s):
        if not root.left and not root.right:
            self.ans += int(s)
            return
        if root.left:
            self.solve(root.left, s + str(root.left.val))
        if root.right:
            self.solve(root.right, s + str(root.right.val))

    def sumNumbers(self, root):
        if root:
            self.solve(root, str(root.val))
        return self.ans
