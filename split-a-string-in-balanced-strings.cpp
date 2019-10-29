// Runtime: 0 ms
// Memory Usage: 8.3 MB
class Solution {
public:
  int balancedStringSplit(string s) {
    int count = 0;
    int res = 0;
    for (char c : s) {
      if (c == 'L') count++;
      else count--;

      if (count == 0) res ++;
    }
    return res;
  }
};