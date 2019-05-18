// Runtime: 104 ms
// Memory Usage: 10.3 MB
class Solution {
public:
  bool isValid(string S) {
    if (S.size() % 3 != 0) return false;

    while (S.size() > 3) {
      bool f = false;
      for (int i = 0; i < S.size() - 2; i++) {
        if (S.substr(i, 3) == "abc") {
          f = true;
          S.erase(i, 3);
          i += 3;
        }
      }
      if (!f) return false;
    }
    return S.size() == 0 || S == "abc";
  }
};

// Runtime: 16 ms
// Memory Usage: 10.8 MB
class Solution {
public:
  bool isValid(string S) {
    if (!S.size() % 3)  return false;

    stack<char> st;

    for (char a : S) {
      if (a == 'c') {
        if (st.empty() || st.top() != 'b')
          return false;
        else st.pop();

        if (st.empty() || st.top() != 'a')
          return false;
        else st.pop();
      }
      else {
        st.push(a);
      }
    }
    return st.size() == 0;
  }
};