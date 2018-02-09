//Runtime: 707 ms
object Solution {
    def minDepth(root: TreeNode): Int = {
        if(root == null) 0
        else if(root.left == null && root.right == null) 1
        else if(root.left == null) 1 + minDepth(root.right)
        else if(root.right == null) 1 + minDepth(root.left)
        else 1 + Math.min(minDepth(root.right), minDepth(root.left))
    }
}
