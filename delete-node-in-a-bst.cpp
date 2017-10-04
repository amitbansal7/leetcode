//Runtime: 32 ms
class Solution {
public:

    TreeNode* find(TreeNode* root)
    {
        while(root->left)
            root = root->left;

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else
        {
            if(!root->left && !root->right)
                return NULL;
            else if(!root->left && root->right)
                root = root->right;
            else if(root->left && !root->right)
                root = root->left;
            else
            {
                TreeNode* temp = find(root->right);
                int del = root->val;
                root->val = temp->val;
                temp->val = del;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};
