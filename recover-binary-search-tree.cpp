//Runtime: 48 ms
class Solution {
public:

    TreeNode* a = nullptr;
    TreeNode* b = nullptr;
    TreeNode* largev = nullptr;
    TreeNode* smallv = nullptr;
    int large = INT_MIN;
    int small = INT_MAX;

    void findSmall(TreeNode* root) {
        if (!root)
            return ;

        if (root->val < small)
        {
            small = root->val;
            smallv = root;
        }

        findSmall(root->left);
        findSmall(root->right);
    }

    void findLarge(TreeNode* root) {
        if (!root)
            return;

        if (root->val > large)
        {
            large = root->val;
            largev = root;
        }

        findLarge(root->left);
        findLarge(root->right);
    }

    void solve(TreeNode* root)
    {
        if (!root || a || b)
            return;

        large = INT_MIN;
        small = INT_MAX;
        findLarge(root->left);
        findSmall(root->right);

        if (small < root->val)
        {
            a = root;
            b = smallv;
            return;
        }

        if (large > root->val) {
            a = root;
            b = largev;
            return;
        }

        solve(root->left);
        solve(root->right);
    }

    void recoverTree(TreeNode* root) {
        solve(root);
        swap(a->val, b->val);
        a = nullptr;
        b = nullptr;
        solve(root);
        if (a && b)
            swap(a->val, b->val);
        a = nullptr;
        b = nullptr;
        solve(root);
        if (a && b)
            swap(a->val, b->val);
    }
};
