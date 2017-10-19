//Runtime: 19 ms
class Solution {
public:
    int ans = INT_MIN;
    int node = INT_MIN;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;

        node = max(node, root->val);
        int a = solve(root->left);
        int b = solve(root->right);
        ans = max(ans, root->val + max(a,b)>0?max(a,b):0);
        ans = max(ans, root->val + a + b);

        if(max(a,b) > 0)
            return max(a,b)+root->val > 0 ?max(a,b)+root->val:0;
        return root->val>0?root->val:0;
    }

    int maxPathSum(TreeNode* root) {
        ans = root->val;
        if(!root->left && !root->right)
            return ans;
        solve(root);

        if(ans!=0)
            return ans;

        return node;
    }
};
