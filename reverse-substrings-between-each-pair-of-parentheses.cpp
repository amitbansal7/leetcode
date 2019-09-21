// Runtime: 0 ms
// Memory Usage: 8.7 MB
class Solution {
public:
  string reverseParentheses(string s) {
    string res = "";
    stack<int> stk;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        stk.push(i);
      } else if (s[i] == ')') {
        int idx = stk.top();
        stk.pop();
        reverse(s.begin() + idx + 1, s.begin() + i);
      }
    }
    for (char a : s) {
      if (a != '(' && a != ')') {
        res += a;
      }
    }
    return res;
  }
};


class Solution {
public:
  string reverseParentheses(string s) {
    string res = "";
    vector<int> pairs(s.size());
    stack<int> open;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        open.push(i);
      } else if (s[i] == ')') {
        int j = open.top();
        open.pop();
        pairs[i] = j;
        pairs[j] = i;
      }
    }
    int direction = 1;
    for (int i = 0; i < s.size(); i += direction) {
      cout << i << " ";
      if (s[i] == '(' || s[i] == ')') {
        i = pairs[i];
        direction = -direction;
      } else {
        res += s[i];
      }
    }
    return res;
  }
};