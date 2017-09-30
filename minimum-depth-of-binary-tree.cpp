//Runtime: 6 ms
class Solution {
public:
    int ans = INT_MAX;

    void traverse(TreeNode* root,int d)
    {
        if(!root)
            return;

        if(!root->left && !root->right)
            ans = min(ans, d);

        traverse(root->left, d+1);
        traverse(root->right, d+1);
    }

    int minDepth(TreeNode* root) {
        if(!root)
            return 0;

        traverse(root, 1);

        return ans;
    }
};
