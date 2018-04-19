//Runtime: 392 ms
object Solution {
  def canJump(nums: Array[Int]): Boolean = {
    nums.zipWithIndex
      .foldLeft((0, 0))((a, b) =>
        if (a._1 < b._2 + b._1 && b._2 <= a._2) (b._2 + b._1, b._2 + b._1)
        else a)
      ._1 >= (nums.size - 1)
  }
}
