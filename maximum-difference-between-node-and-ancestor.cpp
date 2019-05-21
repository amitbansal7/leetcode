// Runtime: 4 ms
// Memory Usage: 13 MB
class Solution {
public:
  int res = -1;
  void solve(TreeNode* root, int mx, int mn) {
    if (!root) return;
    if (mx != -1)
      res = max(res, max(abs(mx - root->val), abs(mn - root->val)));

    mx = max(root->val, mx);
    mn = min(root->val, mn);

    solve(root->left, mx, mn);
    solve(root->right, mx, mn);
  }
  int maxAncestorDiff(TreeNode* root) {
    solve(root, -1, 100000 + 1);
    return res;
  }
};