//My solution
//Runtime: 29 ms
class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root, vector<int> vec,int sum)
    {
        if(!root)
            return;

        for(int i=0;i<vec.size();i++)
        {
            vec[i] += root->val;
            if(vec[i] == sum)
                ans++;
        }
        vec.push_back(root->val);
        if(root->val == sum)
            ans++;
        solve(root->left, vec, sum);
        solve(root->right, vec, sum);
    }

    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;

        vector<int> vec;
        solve(root, vec, sum);
        return ans;
    }
};



//Better solution (learned from Submission Details section)
//Runtime: 19 ms
class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root, int tsum,int sum)
    {
        if(!root)
            return;

        tsum += root->val;
        if(tsum == sum)
            ans++;

        solve(root->left, tsum, sum);
        solve(root->right, tsum, sum);
    }

    void tsolve(TreeNode* root, int sum)
    {
        if(!root)
            return;

        solve(root, 0, sum);
        tsolve(root->left,sum);
        tsolve(root->right,sum);
    }

    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;

        tsolve(root,sum);
        return ans;
    }
};
