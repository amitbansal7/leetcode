# Runtime: 34 ms
class Solution(object):
    def invertTree(self, root):
        if(root):
            self.invertTree(root.left)
            self.invertTree(root.right)
            root.left, root.right = root.right, root.left
            return root
