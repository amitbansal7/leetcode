//Runtime: 6 ms
class Solution {
public:
    int f = 0;
    void solve(TreeNode* root, int sum, int ttl,int l)
    {
        if(!root)
        {
            if(sum == ttl && l)
                f = 1;
            return;
        }

        solve(root->left, sum, root->left?ttl+root->left->val:ttl,root->right?0:1);
        solve(root->right, sum, root->right?ttl+root->right->val:ttl,root->left?0:1);
    }

    bool hasPathSum(TreeNode* root, int sum) {

        if(!root)
            return false;

        solve(root, sum, root->val,0);

        return f;
    }
};
