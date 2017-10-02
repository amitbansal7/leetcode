//Runtime: 6 ms
class Solution {
public:

    void solve(vector<string>&res, string s, TreeNode* root)
    {

        if(!root->left && !root->right)
            res.push_back(s);

        if(root->left)
            solve(res, s+"->"+to_string(root->left->val), root->left);

        if(root->right)
            solve(res, s+"->"+to_string(root->right->val), root->right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        if(!root) return res;
        solve(res, s+to_string(root->val), root);
        return res;
    }
};
