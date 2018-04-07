//Runtime: 464 ms
object Solution {
  def findMaxConsecutiveOnes(nums: Array[Int]): Int = {
    def solve(nums: Array[Int], i: Int, res: Int, acc: Int): Int = {
      if (i >= nums.size) res max acc
      else if (nums(i) == 0) solve(nums, i + 1, res max acc, 0)
      else solve(nums, i + 1, res, acc + 1)
    }
    solve(nums, 0, 0, 0)
  }
}
