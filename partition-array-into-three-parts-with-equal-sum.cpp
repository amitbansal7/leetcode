// Runtime: 68 ms
// Memory Usage: 12.8 MB
class Solution {
public:
  bool canThreePartsEqualSum(vector<int>& A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    if (!sum % 3) return false;
    int target = sum / 3;

    int parts = 0;
    int temp = 0;
    for (int a : A) {
      temp += a;
      if (temp == target) {
        temp = 0;
        parts++;
      }
    }
    return parts == 3;
  }
};