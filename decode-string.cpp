// Runtime: 4 ms
// Memory Usage: 9 MB
class Solution {
public:

  string solve(string s, int &i) {
    string res = "";
    while (i < s.size() && s[i] != ']') {
      if (!isdigit(s[i])) {
        res += s[i++];
      } else {
        int n = 0;
        while (i < s.size() && isdigit(s[i])) {
          n = n * 10 + s[i++] - '0';
        }
        i++;
        string t = solve(s, i);
        i++;

        while (n-- > 0) res += t;
      }
    }

    return res;
  }

  string decodeString(string s) {
    int i = 0;
    return solve(s, i);
  }
};