# Runtime: 438 ms
class Solution(object):

    def match(self, s, t):
        if not s and not t:
            return True

        if s is None or t is None:
            return False

        if s.val != t.val:
            return False

        return self.match(s.left, t.left) and self.match(s.right, t.right)

    def isSubtree(self, s, t):
        if not s:
            return False

        return (s.val == t.val and self.match(s, t)) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
