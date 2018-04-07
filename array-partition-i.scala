//Runtime: 616 ms
object Solution {
  def arrayPairSum(nums: Array[Int]): Int = {
    nums.sorted.zipWithIndex
      .filter(_._2 % 2 == 0)
      .foldLeft((0, 0))((a, b) => (a._1 + b._1, 0))
      ._1
  }
}
