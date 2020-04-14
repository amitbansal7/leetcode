// Runtime: 268 ms
// Memory Usage: 60.5 MB
class Solution {
public:
  void traverse(TreeNode* root, vector<int> &l) {
    if (!root) return;
    traverse(root->left, l);
    l.push_back(root->val);
    traverse(root->right, l);
  }
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> l1, l2;
    traverse(root1, l1);
    traverse(root2, l2);
    vector<int> res;
    int i = 0, j = 0;
    while (i < l1.size() && j < l2.size()) {
      if (l1[i] < l2[j]) {
        res.push_back(l1[i++]);
      } else {
        res.push_back(l2[j++]);
      }
    }
    while (i < l1.size()) {
      res.push_back(l1[i++]);
    }
    while (j < l2.size()) {
      res.push_back(l2[j++]);
    }
    return res;
  }
};