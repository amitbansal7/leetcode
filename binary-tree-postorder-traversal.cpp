//Runtime: 3 ms
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;

        stack<TreeNode*> S;

        if (!root)  return res;

        S.push(root);
        while (!S.empty())
        {
            TreeNode* t = S.top();
            S.pop();
            res.push_back(t->val);
            if (t->left)    S.push(t->left);
            if (t->right)   S.push(t->right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
