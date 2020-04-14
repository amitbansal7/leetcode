// Runtime: 48 ms
// Memory Usage: 31.3 MB
class Solution {
public:
  void solve(TreeNode* root, int &res, int d, int &md) {
    if (!root) return;
    solve(root->left, res, d + 1, md);
    solve(root->right, res, d + 1, md);
    if (!root->left && !root->right) {
      if (d == md) {
        res += root->val;
      } else if (d > md) {
        res = root->val;
      }
    }
    md = max(d, md);
  }
  int deepestLeavesSum(TreeNode* root) {
    int res = 0;
    int md = 0;
    solve(root, res, 0, md);
    return res;
  }
};