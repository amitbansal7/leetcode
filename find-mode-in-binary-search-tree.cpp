//Runtime: 19 ms
class Solution {
public:
    int maxn = 0;
    int c = 0;

    void solve2(TreeNode* root, int val)
    {
        if(!root)
            return;

        if(root->val == val)
            c++;
        solve2(root->left, val);
        solve2(root->right, val);
    }

    void solve(TreeNode* root, vector<int>&res)
    {
        if(!root)
            return;

        c = 0;
        solve2(root, root->val);
        if(c > maxn)
        {
            res.clear();
            res.push_back(root->val);
            maxn = c;
        }
        else if(c == maxn)
            res.push_back(root->val);

        solve(root->left, res);
        solve(root->right, res);
    }

    vector<int> findMode(TreeNode* root)
    {
        vector<int>res;
        solve(root, res);
        return res;
    }
};
