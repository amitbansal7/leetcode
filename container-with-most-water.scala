//Runtime: 372 ms
object Solution {
  def maxArea(height: Array[Int]): Int = {
    def solve(lo: Int, hi: Int, res: Int): Int = {
      if (lo >= hi) res
      else if (height(lo) < height(hi))
        solve(lo + 1, hi, res max ((hi - lo) * (height(lo) min height(hi))))
      else solve(lo, hi - 1, res max ((hi - lo) * (height(lo) min height(hi))))
    }
    solve(0, height.size - 1, Int.MinValue)
  }
}
