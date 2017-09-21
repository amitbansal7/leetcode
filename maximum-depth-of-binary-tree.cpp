//Runtime: 6 ms
class Solution {
public:
    int maxd = INT_MIN;

    void solve(TreeNode* root,int d)
    {
        if(!root)
        {
            maxd = max(maxd, d);
            return ;
        }

        solve(root->left,d+1);
        solve(root->right, d+1);
    }

    int maxDepth(TreeNode* root) {
        solve(root, 0);
        return maxd;
    }
};
