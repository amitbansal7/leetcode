//Runtime: 6 ms
class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root,int l)
    {
        if(!root)
            return;

        if(l && !root->left && !root->right)
            ans += root->val;

        solve(root->left,1);
        solve(root->right,0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};
