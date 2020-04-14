// Runtime: 36 ms
// Memory Usage: 31.3 MB
class Solution {
public:
  void solve(TreeNode* root, int &res, int gp, int p) {
    if (!root) return;
    if (gp == 0) {
      res += root->val;
    }
    solve(root->left, res, p, root->val % 2);
    solve(root->right, res, p, root->val % 2);
  }
  int sumEvenGrandparent(TreeNode* root) {
    int res = 0;
    if (!root) return res;
    solve(root, res, -1, -1);
    return res;
  }
};