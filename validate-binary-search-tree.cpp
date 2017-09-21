//Runtime: 9 ms
//Learned from "discuss" section.
class Solution {
public:

    bool validate(TreeNode* root, TreeNode* minn, TreeNode* maxn)
    {
        if(!root) return 1;

        if((minn && root->val <= minn->val) ||(maxn && root->val >= maxn->val))
            return 0;

        return (validate(root->left, minn, root) && validate(root->right, root, maxn));
    }
    bool isValidBST(TreeNode* root) {

        return validate(root, NULL, NULL);
    }
};
