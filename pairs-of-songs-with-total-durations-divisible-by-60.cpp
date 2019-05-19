// Runtime: 44 ms
// Memory Usage: 11.9 MB
class Solution {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> mp(60, 0);
    int res = 0;
    for (int a : time) {
      int md = a % 60;
      if (!md) res += mp[md];

      else res += mp[60 - md];

      mp[a % 60]++;
    }
    return res;
  }
};