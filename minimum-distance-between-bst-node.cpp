//Runtime: 4 ms
class Solution {
public:
    void solve(TreeNode* root, vector<int>&A) {
        if (!root) return;

        A.push_back(root->val);
        solve(root->left, A);
        solve(root->right, A);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int>A;
        solve(root, A);
        sort(A.begin(), A.end());
        int res = INT_MAX;
        for (int i = 0; i < A.size() - 1; i++)
            res = min(res, A[i + 1] - A[i]);

        return res;
    }
};
