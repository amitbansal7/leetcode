//Runtime: 4 ms
class Solution {
public:

  bool solve(TreeNode* root, vector<int> vec, vector<int>&res, int *idx) {
    if (!root) return true;
    if (root->val != vec[(*idx)++]) return false;

    if (root->left && root->left->val != vec[*idx]) {
      res.push_back(root->val);
      return solve(root->right, vec, res, idx) && solve(root->left, vec, res, idx);
    } else {
      return solve(root->left, vec, res, idx) && solve(root->right, vec, res, idx);
    }
  }

  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> res;
    int idx = 0;
    if (solve(root, voyage, res, &idx)) {
      return res;
    } else return vector<int> { -1};
  }
};