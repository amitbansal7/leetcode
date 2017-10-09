//Runtime: 26 ms
class Solution {
public:
    int f = 1;
    int ans = 0;
    void solve(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2)
            return;

        if(!root1 || !root2)
        {
            f = 0;
            return;
        }

        if(root1->val != root2->val)
        {
            f = 0;
            return;
        }

        solve(root1->left, root2->left);
        solve(root1->right, root2->right);
    }

    void solveh(TreeNode* s, TreeNode* t)
    {
        if(!s)
            return;

        solve(s,t);

        if(f)
        {
            ans = 1;
            return;
        }

        f = 1;

        solveh(s->left,t);
        solveh(s->right,t);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {

        solveh(s,t);
        return ans;
    }
};
