//Runtime: 264 ms
object Solution {

    def findSecondMinimumValue(root: TreeNode): Int = {
        def inorder(root: TreeNode): Set[Int] = root match{
            case null => Set()
            case r: TreeNode => inorder(r.left) ++ Set(r.value) ++ inorder(r.right)
        }
        inorder(root).toList.sortWith(_<_) match{
            case Nil => -1
            case h :: Nil => -1
            case h :: tail=> tail.head
        }
    }
}
