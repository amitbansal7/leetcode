// Runtime: 4 ms
// Memory Usage: 8.2 MB
class Solution {
public:
  string toLowerCase(string str) {
    string res;
    for (char s : str) {
      if (s <= 'Z' && s >= 'A') {
        res += s - 'A' + 'a';
      } else {
        res += s;
      }
    }
    return res;
  }
};