// Runtime: 4 ms
// Memory Usage: 11.1 MB
class Solution {
public:

  TreeNode* solve(vector<int>& preorder, int lo, int hi) {
    if (hi < lo) return NULL;

    TreeNode* root = new TreeNode(preorder[lo]);
    int mid = lo + 1;

    while (mid < preorder.size() && preorder[mid] < root->val)
      mid++;

    mid--;
    root->left = solve(preorder, lo + 1, mid);
    root->right = solve(preorder, mid + 1, hi);
    return root;
  }

  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return solve(preorder, 0, preorder.size() - 1);
  }
};