//Runtime: 8 ms
//Memory Usage: 11.7 MB
class Solution {
public:
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val < val) {
      TreeNode* node = new TreeNode(val);
      node->left = root;
      return node;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
  }
};
