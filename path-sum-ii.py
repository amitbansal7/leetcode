# Runtime: 78 ms
class Solution(object):

    def solve(self, root, sum, temp, res, tar):
        if(root):
            sum += root.val
            if not root.left and not root.right and tar == sum:
                res.append(temp + [root.val])

            self.solve(root.left, sum, temp + [root.val], res, tar)
            self.solve(root.right, sum, temp + [root.val], res, tar)

    def pathSum(self, root, sum):
        res = []
        temp = []
        self.solve(root, 0, temp, res, sum)
        return res
