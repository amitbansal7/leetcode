// Runtime: 196 ms
// Memory Usage: 51.1 MB
class Solution {
public:
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> inout(N + 1, 0);

    for (auto t : trust) {
      inout[t[0]]--;
      inout[t[1]]++;
    }

    for (int i = 1; i <= N; i++) {
      if (inout[i] == N - 1) {
        return i;
      }
    }
    return -1;

  }
};