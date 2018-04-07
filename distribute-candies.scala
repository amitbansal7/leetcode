//Runtime: 772 ms
object Solution {
  def distributeCandies(candies: Array[Int]): Int = {
  	candies.toSet.size min candies.size/2
  }
}