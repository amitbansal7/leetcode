// Runtime: 4 ms
// Memory Usage: 8 MB
class Solution {
public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    auto dim = binaryMatrix.dimensions();
    int m = 0;
    int n = dim[1] - 1;
    int prev = binaryMatrix.get(m, n);
    int res = -1;
    while (m < dim[0] && n >= 0) {
      if (prev == 0) {
        m++;
        if (m < dim[0])
          prev = binaryMatrix.get(m, n);
      } else if (prev == 1) {
        n--;
        if (n >= 0) {
          prev = binaryMatrix.get(m, n);
        } else {
          return n + 1;
        }
        res = n + 1;
      }
    }
    return res;
  }
};