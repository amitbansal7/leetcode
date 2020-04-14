// Runtime: 52 ms
// Memory Usage: 30.1 MB
class FindElements {
public:

  set<int> st;

  void solve(TreeNode* root, int val) {
    if (!root) return;

    root->val = val;
    st.insert(val);
    solve(root->left, val * 2 + 1);
    solve(root->right, val * 2 + 2);
  }

  FindElements(TreeNode* root) {
    solve(root, 0);
  }

  bool find(int target) {
    return st.find(target) != st.end();
  }
};
