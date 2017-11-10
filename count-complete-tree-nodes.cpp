//Runtime: 156 ms
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        int l, r;
        l = r = 0;
        TreeNode* li, *ri;
        li = ri = root;
        while (li)
        {
            li = li->left;
            l++;
        }

        while (ri)
        {
            ri = ri->right;
            r++;
        }

        if (l == r)
            return pow(2, l) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
