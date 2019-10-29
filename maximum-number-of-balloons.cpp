// Runtime: 4 ms
// Memory Usage: 8.9 MB
class Solution {
public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> mp;
    for (char c : text) {
      if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') {
        mp[c]++;
      }
    }
    if (mp.size() != 5) return false;
    int res = INT_MAX;
    for (auto a : mp) {
      res = min(res, (a.first == 'o' || a.first == 'l') ? a.second / 2 : a.second);
    }
    return res;

  }
};