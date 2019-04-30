// Runtime: 8 ms
// Memory Usage: 9 MB
class Solution {
public:
  string removeOuterParentheses(string S) {
    string res;
    string t;
    int count = 0;
    for (char c : S) {
      if (count == 0 && t.size() > 0) {
        res += t.substr(1, t.size() - 2);
        t = "";
      }
      if (c == '(') count++;
      else count--;
      t += c;
    }
    res += t.substr(1, t.size() - 2);
    return res;
  }
};