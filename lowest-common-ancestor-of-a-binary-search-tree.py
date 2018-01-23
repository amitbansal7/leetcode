# Runtime: 133 ms


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if not root:
            return None
        elif root == p or root == q:
            return root
        elif p.val < root.val and q.val > root.val or p.val > root.val and q.val < root.val:
            return root
        elif root.val < p.val and root.val < q.val:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return self.lowestCommonAncestor(root.left, p, q)
