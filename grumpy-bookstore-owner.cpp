// Runtime: 32 ms
// Memory Usage: 11.2 MB
class Solution {
public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int g = 0;
    for (int i = 0; i < customers.size(); i++) {
      if (!grumpy[i]) {
        g += customers[i];
      }
    }
    int res = g;
    for (int i = 0; i < X; i++) {
      if (grumpy[i])
        g += customers[i];
    }
    res = max(res, g);
    for (int i = X; i < customers.size(); i++) {
      if (grumpy[i]) g += customers[i];
      if (grumpy[i - X]) g -= customers[i - X];
      res = max(res, g);
    }
    return res;
  }
};