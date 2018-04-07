//Runtime: 784 ms
object Solution {
  def singleNumber(nums: Array[Int]): Array[Int] = {
    nums
      .groupBy(a => a)
      .mapValues(_.size)
      .filter(_._2 == 1)
      .map(_._1)
      .toArray
  }
}
