# Runtime: 103 ms
class Solution(object):

    def findMin(self, root):
        while root.left:
            root = root.left
        return root

    def deleteNode(self, root, key):
        if not root:
            return root
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
        else:
            if not root.left and not root.right:
                root = None
            elif not root.left:
                root = root.right
            elif not root.right:
                root = root.left
            else:
                temp = self.findMin(root.right)
                root.val = temp.val
                root.right = self.deleteNode(root.right, temp.val)

        return root
