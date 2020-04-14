// Runtime: 4 ms
// Memory Usage: 9.2 MB
class Solution {
public:
  bool checkIfExist(vector<int>& arr) {
    set<int> s;
    for (int a : arr) {
      if (s.find(a * 2) != s.end() || (a % 2 == 0 && s.find(a / 2) != s.end())) {
        return true;
      }
      s.insert(a);
    }
    return false;
  }
};