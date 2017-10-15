//Runtime: 3 ms
class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root, string t)
    {
        if(!root->left && !root->right)
            ans+=stoi(t);

        if(root->left)
            solve(root->left, t+to_string(root->left->val));

        if(root->right)
            solve(root->right, t+to_string(root->right->val));
    }

    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        solve(root,to_string(root->val));
        return ans;
    }
};
