//Runtime: 16 ms
class Solution {
public:

    int ans = INT_MAX;
    void solve(TreeNode* root,int &pre)
    {
        if(!root)
            return;

        solve(root->left, pre);
        ans = min(ans, abs(root->val - pre));
        pre = root->val;
        solve(root->right, pre);
    }

    int getMinimumDifference(TreeNode* root) {
        int pre = INT_MAX;
        solve(root, pre);
        return ans;
    }
};
