// Runtime: 8 ms
// Memory Usage: 10 MB
class Solution {
public:
  int slidingPuzzle(vector<vector<int>>& board) {
    string src = "";
    for (auto a : board) {
      for (auto b : a) {
        src += to_string(b);
      }
    }
    set<string> vis;
    vis.insert(src);
    queue<string> q;
    q.push(src);
    vector<vector<int> > swps = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 1, 5}, {2, 4}};
    int depth = 0;
    string target = "123450";
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        src = q.front();
        q.pop();
        if (src == target) return depth;
        int zero = src.find('0');
        for (int s : swps[zero]) {
          swap(src[zero], src[s]);
          if (vis.find(src) == vis.end()) {
            vis.insert(src);
            q.push(src);
          }
          swap(src[s], src[zero]);
        }
      }
      depth++;
    }
    return -1;
  }
};