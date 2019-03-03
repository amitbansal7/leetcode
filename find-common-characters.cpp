// Runtime: 12 ms
// Memory Usage: 10.4 MB
class Solution {
public:
  vector<string> commonChars(vector<string>& A) {

    vector<vector<int> > cache(A.size(), vector<int>(26, 0));

    for (int i = 0; i < A.size(); i++) {
      for (char c : A[i]) {
        cache[i][c - 'a']++;
      }
    }
    vector<string> res;

    for (int i = 0; i < 26; i++) {
      int count = INT_MAX;
      for (int j = 0; j < A.size(); j++) {
        count = min(count, cache[j][i]);
      }
      string s = "";
      if (count != INT_MAX) {
        for (int c = 0; c < count; c++) {
          res.push_back(s + ((char)('a' + i)));
        }
      }
    }
    return res;
  }
};