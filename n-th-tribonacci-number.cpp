// Runtime: 4 ms
// Memory Usage: 8.2 MB
class Solution {
public:
  int tribonacci(int n) {
    int a(0), b(1), c(1);
    if (n < 2) return n;
    for (int i = 3; i <= n; i++) {
      int t = a + b + c;
      a = b;
      b = c;
      c = t;
    }
    return c;
  }
};