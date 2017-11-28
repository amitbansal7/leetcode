//Runtime: 3 ms
class Solution {
public:
    int findH(TreeNode* root)
    {
        if (!root)
            return 0;

        int a, b;
        a = findH(root->left);
        b = findH(root->right);

        return 1 + max(a, b);
    }

    void solve(vector<vector<string> > &res, TreeNode* root, int l, int r, int h)
    {
        if (!root || l > r)
            return;

        int mid = l + (r - l) / 2;

        res[h][mid] = to_string(root->val);
        solve(res, root->left, l, mid, h + 1);
        solve(res, root->right, mid + 1, r, h + 1);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int h = findH(root);
        vector<vector<string> >res(h, vector<string>(pow(2, h) - 1, ""));
        solve(res, root, 0, pow(2, h) - 1, 0);
        return res;
    }
};
