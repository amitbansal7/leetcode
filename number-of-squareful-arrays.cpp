// Runtime: 4 ms
// Memory Usage: 8.9 MB
class Solution {
public:
  map<int, int> count;
  map<int, vector<int> > adj;
  int res = 0;

  void dfs(int src, int left) {
    count[src]--;
    if (!left) res++;

    for (int a : adj[src]) {
      if (count[a]) {
        dfs(a, left - 1);
      }
    }
    count[src]++;
  }

  int numSquarefulPerms(vector<int>& A) {
    for (int a : A) {
      count[a]++;
    }

    for (auto a : count) {
      for (auto b : count) {
        int sum = a.first + b.first;
        double srt = sqrt(sum);
        if ((srt - floor(srt)) == 0) {
          adj[a.first].push_back(b.first);
        }
      }
    }

    for (auto a : adj) {
      dfs(a.first, A.size() - 1);
    }
    return res;
  }
};