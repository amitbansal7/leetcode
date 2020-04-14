// Runtime: 236 ms
// Memory Usage: 64.6 MB
class Solution {
public:

  bool allUniq(string &s) {
    set<char> st;
    for (char a : s) {
      if (st.find(a) != st.end()) {
        return false;
      }
      st.insert(a);
    }
    return true;
  }

  void solve(vector<string> &arr, string s, int idx, int &res) {
    if (allUniq(s)) {
      if (res < s.size()) {
        res = s.size();
      }
    } else {
      if (s.size() > 0) {
        return;
      }
    }
    for (int i = idx; i < arr.size(); i++) {
      solve(arr, s + arr[i], i + 1, res);
    }
  }

  int maxLength(vector<string>& arr) {
    int res = 0;
    string s = "";
    solve(arr, s, 0, res);
    return res;
  }
};