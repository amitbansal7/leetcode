//Runtime: 536 ms
object Solution {
    def minDiffInBST(root: TreeNode): Int = {
        def find(root: TreeNode, acc:List[Int]) : List[Int] = {
            if(root == null) acc
            else root.value :: find(root.left, acc) ::: find(root.right, List());
        }

        def solve(min:Int, lst:List[Int]) : Int  = lst match {
            case Nil => min
            case x :: Nil => min
            case x :: xs => solve(Math.min(Math.abs(x - xs.head), min), xs)
        }
        solve(Int.MaxValue, find(root, List()).sortWith(_ < _))
    }
}
