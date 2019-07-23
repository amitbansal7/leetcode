// Runtime: 0 ms
// Memory Usage: 8.2 MB

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:

  int firstBadVersion(int n) {
    int lo = 0;
    int hi = n;

    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      bool m = isBadVersion(mid);

      if (m)  hi = mid;
      else  lo = mid + 1;

    }
    return hi;
  }
};