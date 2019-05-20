// Runtime: 0 ms
// Memory Usage: 8.3 MB
class Solution {
public:
  vector<int> dp = vector<int> (32, -1);
  int fib(int N) {
    if (N <= 1)
      dp[N] = N;
    else if (dp[N] != -1)
      return dp[N];
    else dp[N] = fib(N - 1) + fib(N - 2);

    return dp[N];
  }
};