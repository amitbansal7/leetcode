//Runtime: 9 ms
class Solution {
public:

    vector<int> solve(TreeNode* root)
    {
        if(!root)
            return vector<int>(2,0);

        vector<int>left = solve(root->left);
        vector<int>right = solve(root->right);

        vector<int>res(2);

        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
        return res;
    }

    int rob(TreeNode* root) {
        if(!root)
            return 0;
        vector<int>res;
        res = solve(root);
        return max(res[0], res[1]);

    }
};


//Dynamic programming approach
//Runtime: 16 ms
class Solution {
public:

    int solve(TreeNode* root, map<TreeNode*,int> &M)
    {
        if(!root)
            return 0;

        if(M.find(root) != M.end())
            return M[root];

        int ans = root->val;
        if(root->left)
            ans += solve(root->left->left,M) + solve(root->left->right, M);

        if(root->right)
            ans += solve(root->right->left, M) + solve(root->right->right, M);

        return M[root] = max(ans, solve(root->left,M)+solve(root->right, M));
    }

    int rob(TreeNode* root) {
        if(!root)
            return 0;
        map<TreeNode*, int> M;
        return solve(root, M);
    }
};


//Brute force
//Runtime: 1102 ms
class Solution {
public:

    int solve(TreeNode* root, bool prev)
    {
        if(!root)
            return 0;

        if(prev)
        {
            int a = 0;
            a += solve(root->left, 0);
            a += solve(root->right, 0);
            return a;
        }
        else
        {
            int a = root->val;
            int b = 0;

            a += solve(root->left, 1);
            a += solve(root->right, 1);

            b += solve(root->left, 0);
            b += solve(root->right, 0);

            return max(a,b);
        }
    }

    int rob(TreeNode* root) {
        if(!root)
            return 0;

        return solve(root, 0);
    }
};
