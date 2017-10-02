// Runtime: 12 ms
class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int> temp, int tsum, TreeNode* root, int sum)
    {
        if(!root)
            return;

        temp.push_back(root->val);
        tsum += root->val;

        if(!root->left && !root->right && tsum == sum)
            res.push_back(temp);

        solve(res, temp, tsum, root->left, sum);
        solve(res, temp, tsum, root->right, sum);
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> temp;
        solve(res, temp, 0, root, sum);
        return res;
    }
};
