// Runtime: 48 ms
// Memory Usage: 23.7 MB
class Solution {
public:

  TreeNode* solve(TreeNode* root, int sum, int limit) {
    if (!root) return NULL;

    sum += root->val;

    if (!root->left && !root->right) {
      return (sum < limit) ? (NULL) : root;
    }

    root->left = solve(root->left, sum, limit);
    root->right = solve(root->right, sum, limit);

    if (!root->left && !root->right)
      return NULL;

    return root;
  }

  TreeNode* sufficientSubset(TreeNode* root, int limit) {
    return solve(root, 0, limit);
  }
};