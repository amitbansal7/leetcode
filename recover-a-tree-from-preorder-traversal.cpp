// Runtime: 56 ms
// Memory Usage: 357.1 MB
class Solution {
public:
  int idx = 0;
  TreeNode* solve(string s, int depth) {
    int dash = 0;

    while (s[idx + dash] == '-') {
      dash++;
    }

    if (depth != dash) return NULL;

    int itr = idx + dash;

    while (itr < s.size() && s[itr] != '-')
      itr++;

    int num = stoi(s.substr(idx + dash, itr - idx - dash));

    idx = itr;

    TreeNode* root = new TreeNode(num);
    root->left = solve(s, depth + 1);
    root->right = solve(s, depth + 1);

    return root;

  }

  TreeNode* recoverFromPreorder(string S) {
    return solve(S, 0);
  }
};