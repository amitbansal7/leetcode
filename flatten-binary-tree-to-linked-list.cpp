//Runtime: 6 ms
class Solution {
public:

    TreeNode* findlast(TreeNode* root)
    {
        while(root->right)
            root = root->right;
        return root;
    }

    TreeNode* solve(TreeNode* root)
    {
        if(!root)
            return NULL;

        TreeNode* tright = root->right;
        root->right = root->left;
        root->left  = NULL;
        root->right = solve(root->right);
        TreeNode* last = findlast(root);
        last->right = solve(tright);
        return root;
    }

    void flatten(TreeNode* root) {
       if(!root)
           return;
        solve(root);
    }
};
