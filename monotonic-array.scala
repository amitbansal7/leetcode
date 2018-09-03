//Runtime: 936 ms
object Solution {
  def isMonotonic(A: Array[Int]): Boolean = {
    (A.toList == A.sorted.toList) || (A.reverse.toList == A.sorted.toList)
  }
}
