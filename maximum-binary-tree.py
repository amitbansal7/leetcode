# Runtime: 239 ms
class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        if len(nums) == 0:
            return None

        t = 0
        for i in range(len(nums)):
            if nums[t] < nums[i]:
                t = i

        root = TreeNode(nums[t])
        root.left = self.constructMaximumBinaryTree(nums[:t])
        root.right = self.constructMaximumBinaryTree(nums[t + 1:])
        return root
