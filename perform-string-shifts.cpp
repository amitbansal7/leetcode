// Runtime: 4 ms
// Memory Usage: 7.1 MB
class Solution {
public:
  string stringShift(string s, vector<vector<int>>& shift) {
    int right = 0;
    for (auto a : shift) {
      right += a[0] ? a[1] : (-1 * a[1]);
    }
    string t = "";
    while (right != 0) {
      if (right > 0) {
        t = s[s.size() - 1] + s.substr(0, s.size() - 1);
        right--;
      } else {
        t = s.substr(1, s.size() - 1) + s[0];
        right++;
      }
      s = t;
    }
    return s;
  }
};