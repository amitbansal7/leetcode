# Runtime: 66 ms
class Solution(object):
    global target

    def solve(self, root, sum):
        if(root):
            sum = sum + root.val
            if not root.left and not root.right:
                if sum == self.target:
                    return True

            return self.solve(root.left, sum) or self.solve(root.right, sum)

        return False

    def hasPathSum(self, root, sum):
        self.target = sum
        return self.solve(root, 0)
