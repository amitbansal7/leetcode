// Runtime: 20 ms
// Memory Usage: 18.8 MB
class Solution {
public:

  TreeNode* solve(TreeNode* root, unordered_set<int> &del, vector<TreeNode*> &res) {
    if (!root) return root;

    TreeNode* ret = root;
    if (del.find(root->val) != del.end()) {
      ret = NULL;
    }

    root->left = solve(root->left, del, res);
    root->right = solve(root->right, del, res);

    if (root->left && !ret)
      res.push_back(root->left);

    if (root->right && !ret)
      res.push_back(root->right);

    return ret;
  }

  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    unordered_set<int> del(to_delete.begin(), to_delete.end());
    vector<TreeNode*> res;
    root = solve(root, del, res);
    if (root)
      res.push_back(root);
    return res;
  }
};