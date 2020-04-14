// Runtime: 0 ms
// Memory Usage: 8.5 MB
class Solution {
public:
  string freqAlphabets(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
      if (i + 2 < s.size() && s[i + 1] != '#' && s[i + 2] == '#') {
        res += 'a' - 1 + ((s[i++] - '0') * 10 + s[i++] - '0');
      } else {
        res += 'a' - 1 + (s[i] - '0');
      }
    }
    return res;
  }
};