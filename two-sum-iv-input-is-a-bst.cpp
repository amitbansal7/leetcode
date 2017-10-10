//Runtime: 36 ms
class Solution {
public:
    TreeNode* temp;
    bool find(TreeNode* root, int f)
    {
        if(!root)
            return 0;

        if(root->val == f)
            temp = root;

        return find(root->left, f) | find(root->right, f);
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
