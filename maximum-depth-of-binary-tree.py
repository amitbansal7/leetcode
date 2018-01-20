# Runtime: 56 ms
class Solution(object):
    def maxDepth(self, root):
        if not root:
            return 0

        a = self.maxDepth(root.left)
        b = self.maxDepth(root.right)

        return 1 + max(a, b)
