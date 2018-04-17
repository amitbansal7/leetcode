//Runtime: 480 ms
object Solution {
  def pathSum(root: TreeNode, sum: Int): List[List[Int]] = {
    def solve(node: TreeNode, tSum: Int, temp: List[Int]): List[List[Int]] =
      node match {
        case null => List()
        case node: TreeNode
            if (sum == tSum + node.value && node.left == null && node.right == null) =>
          List(temp :+ node.value)
        case _ =>
          solve(node.left, tSum + node.value, temp :+ node.value) :::
            solve(node.right, tSum + node.value, temp :+ node.value)
      }
    solve(root, 0, List())
  }
}
