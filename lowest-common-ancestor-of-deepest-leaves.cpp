// Runtime: 16 ms
// Memory Usage: 19.5 MB
class Solution {
public:

  int findD(TreeNode* root) {
    if (!root) return 0;
    int l = findD(root->left);
    int r = findD(root->right);
    return 1 + max(l, r);
  }

  TreeNode* lca(TreeNode* root, int d, int md) {
    if (!root) return NULL;

    if (!root->left && !root->right) {
      return (d == md) ? root : NULL;
    }

    TreeNode* l = lca(root->left, d + 1, md);
    TreeNode* r = lca(root->right, d + 1, md);


    if (l && r) return root;
    return l ? l : r;
  }

  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    int depth = findD(root);
    return lca(root, 1, depth);
  }
};