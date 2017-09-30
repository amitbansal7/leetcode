//Runtime: 9 ms
class Solution {
public:

    int ans = 1;
    int traverse(TreeNode* root, int h)
    {
        if(!root)
            return h;

        int a = traverse(root->left, h+1);
        int b = traverse(root->right, h+1);

        if(abs(a-b) > 1)
            ans = 0;

        return max(a,b);
    }

    bool isBalanced(TreeNode* root) {
        traverse(root,0);
        return ans;
    }
};
