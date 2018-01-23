# Runtime: 114 ms


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if not root:
            return None
        elif root == q or root == p:
            return root
        else:
            left = self.lowestCommonAncestor(root.left, p, q)
            right = self.lowestCommonAncestor(root.right, p, q)

            if left == None and right == None:
                return None
            elif left and right:
                return root
            elif left:
                return left
            elif right:
                return right
