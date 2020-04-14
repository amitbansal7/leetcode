// Runtime: 0 ms
// Memory Usage: 8.5 MB
class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    vector<int> res;
    for (int i = 1; i < n; i++) {
      string s = to_string(i) + to_string(n - i);
      if (s.find('0') == string::npos) {
        res.push_back(n - i);
        res.push_back(i);
        return res;
      }
    }
    return res;
  }
};