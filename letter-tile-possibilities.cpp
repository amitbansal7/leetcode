// Runtime: 16 ms
// Memory Usage: 13.3 MB
class Solution {
public:

  void solve(vector<int> count, int d, int len, int &res) {
    if (d != 0)
      res++;

    if (d == len)
      return;

    for (int i = 0; i < count.size(); i++) {
      if (count[i]) {
        count[i]--;
        solve(count, d + 1, len, res);
        count[i]++;
      }
    }
  }

  int numTilePossibilities(string tiles) {
    map<char, int> mp;
    for (char a : tiles) {
      mp[a]++;
    }
    vector<int> count;
    for (auto a : mp) {
      count.push_back(a.second);
    }

    int res = 0;
    solve(count, 0, tiles.size(), res);

    return res;
  }
};