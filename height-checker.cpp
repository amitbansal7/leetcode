// Runtime: 4 ms
// Memory Usage: 8.6 MB
class Solution {
public:
  int heightChecker(vector<int>& heights) {
    vector<int> t(heights.begin(), heights.end());

    sort(t.begin(), t.end());

    int res = 0;
    for (int i = 0; i < t.size(); i++) {
      if (t[i] != heights[i]) {
        res++;
      }
    }
    return res;
  }
};