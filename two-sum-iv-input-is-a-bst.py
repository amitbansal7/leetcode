# Runtime: 145 ms
class Solution(object):
    global mainroot

    def find(self, root, f, avoid):
        if not root:
            return False

        if root.val == f and root != avoid:
            return True

        if root.val < f:
            return self.find(root.right, f, avoid)

        return self.find(root.left, f, avoid)

    def solve(self, root, k):
        if not root:
            return False

        if self.find(self.mainroot, k - root.val, root):
            return True

        return self.solve(root.left, k) or self.solve(root.right, k)

    def findTarget(self, root, k):
        self.mainroot = root
        return self.solve(root, k)
