// Runtime: 0 ms
// Memory Usage: 8.3 MB
class Solution {
public:
  int bitwiseComplement(int N) {
    if (!N) return 1;
    vector<bool> binary;
    while (N) {
      binary.push_back((N % 2 + 1) % 2);
      N /= 2;
    }
    int res = 0;
    for (int i = 0; i < binary.size(); i++) {
      res += binary[i] * pow(2, i);
    }
    return res;
  }
};