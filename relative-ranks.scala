//Runtime: 1132 ms
object Solution {
  def findRelativeRanks(nums: Array[Int]): Array[String] = {
    val t = nums.zipWithIndex.sortWith(_._1 > _._1)

    val res = new Array[String](nums.size)

    for ((a, c) <- t.zipWithIndex) {
      if (c == 0) res(a._2) = "Gold Medal"
      else if (c == 1) res(a._2) = "Silver Medal"
      else if (c == 2) res(a._2) = "Bronze Medal"
      else res(a._2) = (c + 1).toString
    }
    res
  }
}
