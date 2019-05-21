// Runtime: 8 ms
// Memory Usage: 20 MB
class Solution {
public:
  void solve(TreeNode* root, string t, string &res) {
    if (!root) return;
    t = (char)(root->val + 'a') + t;
    solve(root->left, t, res);
    solve(root->right, t, res);
    if (!root->left && !root->right && t < res) {
      res = t;
    }
  }

  string smallestFromLeaf(TreeNode* root) {
    string res = "~";
    solve(root, "", res);
    return res;
  }
};