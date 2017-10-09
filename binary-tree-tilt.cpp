//Runtime: 16 ms
class Solution {
public:

    int tilt = 0;

    int solve(TreeNode* root)
    {
        if(!root)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);
        tilt += abs(l-r);

        return l+r+root->val;
    }

    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        solve(root);
        return tilt;
    }
};
