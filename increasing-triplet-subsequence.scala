//Runtime: 336 ms
object Solution {
  def increasingTriplet(nums: Array[Int]): Boolean = {
    def solve(i: Int, a: Int, b: Int): Boolean = {
      if (i >= nums.size) false
      else if (nums(i) <= a) solve(i + 1, nums(i), b)
      else if (nums(i) <= b) solve(i + 1, a, nums(i))
      else true
    }
    solve(0, Int.MaxValue, Int.MaxValue)
  }
}
