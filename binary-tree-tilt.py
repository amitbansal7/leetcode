# Runtime: 79 ms
class Solution(object):
    def findTilt(self, root):
        self.res = 0

        def solve(root):
            if not root:
                return 0

            a = solve(root.left)
            b = solve(root.right)
            self.res += abs(a - b)
            return a + b + root.val

        solve(root)
        return self.res
