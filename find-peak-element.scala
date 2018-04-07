//Runtime: 344 ms
object Solution {
    def findPeakElement(nums: Array[Int]): Int = {
        def solve(nums: Array[Int], lo: Int, hi: Int): Int = {
            val mid = lo + (hi - lo)/2;
            if(lo == hi) lo
            else if(nums(mid) > nums(mid+1)) solve(nums, lo, mid)
            else solve(nums, mid+1, hi)
        }
        solve(nums, 0, nums.size - 1)
    }
}