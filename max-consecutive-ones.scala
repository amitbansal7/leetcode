//Runtime: 452 ms
object Solution {
  def findMaxConsecutiveOnes(nums: Array[Int]): Int = {
    def count(i: Int, nums: Array[Int], acc: Int): Int = {
      if (i >= nums.size || nums(i) == 0) acc
      else count(i + 1, nums, acc + 1)
    }

    def solve(nums: Array[Int], res: Int, i: Int): Int = {
      if (i >= nums.size) res
      else {
        val c = count(i, nums, 0)
        solve(nums, res max c, i + c + 1)
      }
    }

    solve(nums, 0, 0)
  }
}
