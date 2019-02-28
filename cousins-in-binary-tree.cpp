// Runtime: 8 ms
// Memory Usage: 11.9 MB
class Solution {
public:

  TreeNode* findParent(TreeNode* root, int d, int val, int &depth) {
    if (!root) return NULL;

    if (root->left && root->left->val == val) {
      depth = d;
      return root;
    }

    if (root->right && root->right->val == val) {
      depth = d;
      return root;
    }

    TreeNode* l = findParent(root->left, d + 1, val, depth);
    if (l != NULL) {
      return l;
    }

    return findParent(root->right, d + 1, val, depth);
  }

  bool isCousins(TreeNode* root, int x, int y) {
    int xd = -1;
    int yd = -1;
    TreeNode* lp = findParent(root, 0, x, xd);
    TreeNode* rp = findParent(root, 0, y, yd);
    return lp != rp && xd == yd;
  }
};