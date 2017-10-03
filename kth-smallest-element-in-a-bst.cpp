//Runtime: 16 ms
class Solution {
public:

    void InorderTraversal(TreeNode* root, vector<int> &inorder)
    {
        if(!root)
            return;

        InorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        InorderTraversal(root->right, inorder);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted;
        InorderTraversal(root, sorted);
        return sorted[k-1];
    }
};
