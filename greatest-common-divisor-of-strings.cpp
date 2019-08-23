// Runtime: 8 ms
// Memory Usage: 9.3 MB
class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str1 == str2) return str1;

    if ((str1 + str2) == (str2 + str1)) {
      int gcd = __gcd(str1.size(), str2.size());
      return str1.substr(0, gcd);
    }
    return "";
  }
};