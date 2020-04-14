// Runtime: 4 ms
// Memory Usage: 8.8 MB
class Solution {
public:

  void backtrack(vector<char> digits, int idx, string s, int low, int hi, vector<int> &res) {
    int si;
    istringstream ss(s);
    ss >> si;
    if (si >= low && si <= hi) {
      res.push_back(si);
    }
    if (si > hi) return;
    if (idx >= digits.size()) return;
    backtrack(digits, idx + 1, s + digits[idx], low, hi, res);

  }
  vector<int> sequentialDigits(int low, int high) {
    vector<char> digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<int> res;
    string s = "";
    for (int i = 0; i < digits.size(); i++) {
      backtrack(digits, i, s, low, high, res);
    }
    sort(res.begin(), res.end());
    return res;
  }
};