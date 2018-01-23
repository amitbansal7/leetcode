# Runtime: 47 ms
class Solution(object):

    def solve(self, root, t, res):
        if not root:
            return

        t += "->" + str(root.val)
        if not root.left and not root.right:
            res.append(t[2:])
            return

        self.solve(root.left, t, res)
        self.solve(root.right, t, res)

    def binaryTreePaths(self, root):
        res = []
        self.solve(root, "", res)
        return res
