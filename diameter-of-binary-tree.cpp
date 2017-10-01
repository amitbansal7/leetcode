//Runtime: 9 ms
class Solution {
public:
    int ans = 0;

    int traverse(TreeNode* root)
    {
        if(!root)
            return 0;

        int a = traverse(root->left);
        int b = traverse(root->right);

        ans = max(ans, a+b);
        return max(a,b)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        traverse(root);

        return ans;
    }
};
