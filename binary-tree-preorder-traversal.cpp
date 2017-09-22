//Runtime: 3 ms
class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;

        if(!root) return res;

        stack<TreeNode*> S;
        S.push(root);

        while(!S.empty())
        {
            TreeNode* t = S.top();
            S.pop();
            res.push_back(t->val);

            if(t->right) S.push(t->right);
            if(t->left) S.push(t->left);

        }
        return res;
    }
};
