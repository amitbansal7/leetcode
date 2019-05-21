// Runtime: 4 ms
// Memory Usage: 16.6 MB
class Solution {
public:
  map<int, map<int, priority_queue<int, vector<int>, greater<int> > > > mp;
  void solve(TreeNode* root, int l, int r) {
    if (!root) return;
    mp[l][r].push(root->val);
    solve(root->left, l - 1, r + 1);
    solve(root->right, l + 1, r + 1);
  }
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    solve(root, 0, 0);
    vector<vector<int> > res;

    for (auto a : mp) {
      vector<int> t;
      for (auto b : a.second) {
        while (!b.second.empty()) {
          t.push_back(b.second.top());
          b.second.pop();
        }
      }
      res.push_back(t);
    }

    return res;
  }
};