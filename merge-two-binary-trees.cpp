//Runtime: 48 ms
class Solution {
public:

    TreeNode* merge(TreeNode* t1, TreeNode* t2)
    {
        if(t1 && t2)
        {
            TreeNode* root = new TreeNode(t1->val+t2->val);
            root->left = merge(t1->left, t2->left);
            root->right = merge(t1->right, t2->right);
            return root;
        }

        else if(t1)
            return t1;

        else if(t2)
            return t2;

        return NULL;
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root = NULL;
        root = merge(t1, t2);
        return root;
    }
};
