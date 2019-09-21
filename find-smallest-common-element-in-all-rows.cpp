// Runtime: 148 ms
// Memory Usage: 28 MB
class Solution {
public:
  int smallestCommonElement(vector<vector<int>>& mat) {
    map<int, int> mp;
    for (auto A : mat) {
      for (int a : A) {
        mp[a]++;
      }
    }
    for (auto a : mp) {
      if (a.second == mat.size()) {
        return a.first;
      }
    }
    return -1;
  }
};