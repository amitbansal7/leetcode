//Runtime: 19 ms
class Solution {
public:
    int maxn = -1;
    map<int, int> M;

    int solve(TreeNode* root)
    {
        if (!root)
            return 0;

        int a = root->val + solve(root->left) + solve(root->right);
        M[a]++;
        maxn = max(maxn, M[a]);

        return a;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        vector<int>res;
        for (auto m : M)
            if (m.second == maxn)
                res.push_back(m.first);

        return res;
    }
};
