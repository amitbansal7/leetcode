//Runtime: 39 ms
class Solution {
public:

    void solve(TreeNode* root, int &s)
    {
        if(!root)
            return;

        solve(root->right, s);
        root->val += s;
        s = root->val;
        solve(root->left, s);
    }

    TreeNode* convertBST(TreeNode* root) {
        int s = 0;
        solve(root, s);
        return root;
    }
};
