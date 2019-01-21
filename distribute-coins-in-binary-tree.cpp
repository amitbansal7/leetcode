//Runtime: 4 ms
class Solution {
public:

  int solve(TreeNode* root, int* res) {
    if (!root) return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);
    *res += abs(l) + abs(r);
    return root->val + l + r - 1;
  }

  int distributeCoins(TreeNode* root) {
    int res = 0;
    solve(root, &res);
    return res;
  }
};