//Runtime: 4 ms
class Solution {
public:
  int val = -1;
  bool isUnivalTree(TreeNode* root) {
    if (val == -1 && root) {
      val = root->val;
    }
    return (!root || (!root || root->val == val)
            && isUnivalTree(root->left)
            && isUnivalTree(root->right));
  }
};