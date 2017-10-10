//Runtime: 32 ms
class Solution {
public:
    TreeNode* temp;
    void find(TreeNode* root, int f)
    {
        if(!root)
            return;

        if(root->val == f)
            temp = root;

        if(f < root->val)
            find(root->left, f);
        else
            find(root->right, f);
    }

    bool ans = 0;

    TreeNode* mainroot;
    void solve(TreeNode* root, int t)
    {
        if(!root)
            return;

        find(mainroot, t-root->val);
        if(temp!=NULL && temp!=root)
        {
            ans = 1;
            return;
        }

        temp = NULL;
        solve(root->left, t);
        solve(root->right, t);
    }

    bool findTarget(TreeNode* root, int k)
    {
        if(!root)
            return 0;
        mainroot = root;
        solve(root, k);
        return ans;
    }
};
