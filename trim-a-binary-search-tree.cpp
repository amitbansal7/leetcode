//Runtime: 16 ms
class Solution {
public:
    TreeNode* Create(TreeNode* root, int n)
    {
        if(root == NULL)
            root =  new TreeNode(n);
        else if(n <= root->val)
            root->left = Create(root->left, n);
        else
            root->right = Create(root->right, n);

        return root;
    }

    TreeNode* traverse(TreeNode* root, TreeNode* result, int l,int r)
    {
        if(root == NULL)
            return result;

        if(root->val >=l && root->val <= r)
            result = Create(result,root->val);

        if(root->left)
            result = traverse(root->left, result, l, r);

        if(root->right)
            result = traverse(root->right, result, l, r);

        return result;
    }

    TreeNode* trimBST(TreeNode* root, int L, int R) {

        TreeNode* result = NULL;

        result = traverse(root, result, L,R);

        return result;

    }
};
