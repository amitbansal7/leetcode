//Runtime: 516 ms
object Solution {
    def isValidBST(root: TreeNode): Boolean = {
        def solve(root:TreeNode, a:TreeNode, b:TreeNode): Boolean = root match {
            case null => true
            case t:TreeNode =>
                if((a != null && root.value <= a.value) || (b != null && root.value >= b.value)) false
                else solve(root.left, a, root) && solve(root.right, root, b)
        }
        solve(root, null, null)
    }
}