//Runtime: 66 ms
class Solution {
public:
    int ans = -1;
    int z = 0;
    int solve(TreeNode* root, int node,int c)
    {
        if(!root)
            return 0;

        if(root->val!=node)
            return 0;

        int a = solve(root->left, node,c);
        int b = solve(root->right, node,c);
        if(c == 0)
            z = a+b+1;

        c = max(a,b) +1;
        return c;
    }

    void solve2(TreeNode* root)
    {
        if(!root)
            return;

        solve(root, root->val,0);

        ans = max(ans, z);
        z = 0;
        solve2(root->left);
        solve2(root->right);
    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        solve2(root);
        return ans-1;
    }
};
