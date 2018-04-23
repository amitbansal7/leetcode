//Runtime: 2156 ms
object Solution {

  def findMin(root: TreeNode): Int = {
    if (root.left == null) root.value
    else findMin(root.left)
  }

  def deleteNode(root: TreeNode, key: Int): TreeNode = {
    if (root == null) root
    else if (root.value > key) root.left = deleteNode(root.left, key)
    else if (root.value < key) root.right = deleteNode(root.right, key)
    else {
      if (root.left == null && root.right == null) return null
      else if (root.left == null && root.right != null) return root.right
      else if (root.right == null && root.left != null) return root.left
      else {
        val min = findMin(root.right)
        root.value = min
        root.right = deleteNode(root.right, min)
      }
    }
    root
  }
}
