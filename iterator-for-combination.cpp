// Runtime: 12 ms
// Memory Usage: 14.4 MB
class CombinationIterator {
private:
  vector<string> res;
  int curr = 0;
  void backtrack(string &chars, int idx, string s, int &len) {
    if (s.size() == len) {
      res.push_back(s);
      return;
    }
    for (int i = idx; i < chars.size(); i++) {
      if (s.size() == 0 || s[s.size() - 1] < chars[i]) {
        backtrack(chars, i + 1, s + chars[i], len);
      }
    }
  }
public:
  CombinationIterator(string characters, int combinationLength) {
    backtrack(characters, 0, "", combinationLength);
  }
  string next() {
    return res[curr++];
  }

  bool hasNext() {
    return curr < res.size();
  }
};
