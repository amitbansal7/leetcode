// Runtime: 160 ms
// Memory Usage: 58.3 MB
class Solution {
public:
  long res = 0;
  long total = 0;
  long solve(TreeNode* root) {
    if (!root) return 0;
    long curr = solve(root->left) + solve(root->right) + root->val;
    res = max(res, curr * (total - curr));
    return curr;

  }
  int maxProduct(TreeNode* root) {
    total = solve(root);
    solve(root);
    return res % (int)(1e9 + 7);
  }
};