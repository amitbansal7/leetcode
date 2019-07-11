// Runtime: 4 ms
// Memory Usage: 8.3 MB
class Solution {
public:
  string defangIPaddr(string address) {
    string res;
    for (char a : address) {
      if (a == '.') res += "[.]";
      else res += a;
    }
    return res;
  }
};