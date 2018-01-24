# Runtime: 45 ms


class Solution(object):

    def solve(self, left, right):
        if not left and not right:
            return True
        if not left or not right:
            return False
        if left.val != right.val:
            return False
        return self.solve(left.left, right.right) and self.solve(left.right, right.left)

    def isSymmetric(self, root):
        if not root:
            return True
        return self.solve(root.left, root.right)
