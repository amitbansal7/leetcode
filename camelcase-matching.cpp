// Runtime: 4 ms
// Memory Usage: 8.4 MB
class Solution {
public:

  bool match(string &q, string &p) {
    int j = 0;
    for (char c : q) {
      if (c != p[j] && isupper(c)) return false;
      if (c == p[j]) {
        j++;
      }
    }
    return j == p.size();
  }

  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> res;
    for (string q : queries) {
      res.push_back(match(q, pattern));
    }
    return res;
  }
};