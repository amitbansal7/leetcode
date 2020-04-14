// Runtime: 88 ms
// Memory Usage: 19 MB
class Solution {
public:
  int minSteps(string s, string t) {
    vector<int> mp(26, 0);
    for (char c : s) {
      mp[c - 'a']++;
    }
    for (char c : t) {
      mp[c - 'a']--;
    }
    int res = 0;
    for (int a : mp) {
      if (a > 0) {
        res += a;
      }
    }
    return res;
  }
};