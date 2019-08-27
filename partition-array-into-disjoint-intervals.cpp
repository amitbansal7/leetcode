// Runtime: 40 ms
// Memory Usage: 10.9 MB
class Solution {
public:
  int partitionDisjoint(vector<int>& A) {
    int mx = A[0];
    int res = 0;
    int localMax = A[0];

    for (int i = 1; i < A.size(); i++) {
      if (A[i] < localMax) {
        res = i;
        localMax = mx;
      }
      mx = max(mx, A[i]);
    }
    return res + 1;
  }
};