//Runtime: 384 ms
object Solution {
    def maxDepth(root: TreeNode): Int = {
        def solve(root: TreeNode, d: Int): Int  = root match{
            case null => 0
            case r: TreeNode if(r.left == null && r.right == null) => d
            case _ => solve(root.left, d+1) max solve(root.right, d+1)
        }
        solve(root, 1)
    }
}
