// Runtime: 4 ms
// Memory Usage: 8.3 MB
class Solution {
public:
  int numberOfSteps (int num) {
    int res = 0;
    while (num) {
      res++;
      if (num % 2 == 0) {
        num = num / 2;
      } else {
        num--;
      }
    }
    return res;
  }
};