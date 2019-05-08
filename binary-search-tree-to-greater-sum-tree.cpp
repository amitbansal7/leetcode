// Runtime: 4 ms
// Memory Usage: 9.2 MB
class Solution {
public:

  int solve(TreeNode* root, int acc) {
    if (!root) return acc;

    acc = solve(root->right, acc);
    acc += root->val;
    root->val = acc;
    return solve(root->left, acc);
  }

  TreeNode* bstToGst(TreeNode* root) {
    solve(root, 0);
    return root;
  }
};