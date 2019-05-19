// Runtime: 352 ms
// Memory Usage: 782.7 MB
class Solution {
public:
  string removeDuplicates(string S) {
    stack<char> s;
    for (char a : S) {
      bool f = true;
      while (!s.empty() && s.top() == a) {
        s.pop();
        f = false;
      }
      if (f) s.push(a);
    }
    string res;
    while (!s.empty()) {
      res = s.top() + res;
      s.pop();
    }
    return res;
  }
};