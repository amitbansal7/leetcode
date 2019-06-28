// Runtime: 164 ms
// Memory Usage: 29 MB
class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    vector<int> res;
    int sum = 0;
    for (int i = 0; i < queries.size(); i++) {
      if (i == 0) {
        A[queries[i][1]] += queries[i][0];
        for (int a : A) {
          if (a % 2 == 0) {
            sum += a;
          }
        }
        res.push_back(sum);

      } else {
        if (queries[i][0] != 0) {
          int cur = A[queries[i][1]];
          A[queries[i][1]] += queries[i][0];
          int now = A[queries[i][1]];
          if (cur % 2 == 0 && now % 2 == 0) {
            sum += queries[i][0];
          } else if (now % 2 == 0) {
            sum += now;
          } else if (cur % 2 == 0)
            sum -= cur;
        }

        res.push_back(sum);
      }
    }
    return res;

  }
};