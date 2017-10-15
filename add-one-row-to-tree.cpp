//Runtime: 19 ms
class Solution {
public:

    void solve(TreeNode* root, int v, int d, int lvl)
    {
        if(!root)
            return;

        if(d == lvl)
        {
            TreeNode* left = new TreeNode(v);
            TreeNode* right = new TreeNode(v);

            left->left = root->left;
            root->left = left;

            right->right = root->right;
            root->right = right;
            return ;
        }

        solve(root->left, v, d, lvl+1);
        solve(root->right, v, d, lvl+1);

    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) {

        if(d == 1)
        {
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }

        solve(root, v, d-1, 1);
        return root;
    }
};
