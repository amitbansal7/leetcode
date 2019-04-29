// Runtime: 16 ms
// Memory Usage: 19.9 MB
class Solution {
public:
  void solve(TreeNode* root, string num, vector<string>&s) {
    if (!root) return;
    num += to_string(root->val);
    if (!root->left && !root->right) {
      s.push_back(num);
    } else {
      solve(root->left, num, s);
      solve(root->right, num, s);
    }
  }

  int convert(string s) {
    int num = 0;
    int idx = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      num += ((s[i] - '0') * pow(2, idx++));
    }
    return num;
  }

  int sumRootToLeaf(TreeNode* root) {
    vector<string> acc;
    string s = "";
    solve(root, s, acc);
    int res = 0;
    for (string a : acc) {
      res += convert(a);
    }
    return res;
  }
};

// Runtime: 12 ms
// Memory Usage: 17.1 MB
class Solution {
public:
  void solve(TreeNode* root, int curr, int &res) {
    if (!root) return;

    int num = (curr * 2 + root->val);

    if (!root->left && !root->right) {
      res += num;
    } else {
      solve(root->left, num, res);
      solve(root->right, num, res);
    }
  }

  int sumRootToLeaf(TreeNode* root) {
    int res = 0;
    solve(root, 0, res);
    return res;
  }
};