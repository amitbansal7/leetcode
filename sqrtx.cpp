// Runtime: 4 ms
// Memory Usage: 8.2 MB
class Solution {
public:
  int mySqrt(int x) {
    int hi = x;
    int lo = 0;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      long long sq = (long long)mid * (long long)mid;
      long long sq1 = ((long long)mid + 1) * ((long long)mid + 1);
      if (sq <= x && sq1 > x) return mid;

      if (sq < x)
        lo = mid + 1;
      else
        hi = mid;
    }
    return 0;
  }
};