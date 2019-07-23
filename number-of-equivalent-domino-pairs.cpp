// Runtime: 40 ms
// Memory Usage: 23.4 MB
class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    map<int, int> mp;
    for (auto a : dominoes) {
      mp[min(a[0], a[1]) * 10 + max(a[0], a[1])]++;
    }
    int res = 0;
    for (auto a : mp) {
      int n = a.second;
      res += (n * (n - 1)) / 2;
    }

    return res;
  }
};