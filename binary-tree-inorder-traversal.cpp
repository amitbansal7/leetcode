//Recursive
//Runtime: 0 ms
class Solution {
public:
    vector<int>res;

    void inorder(TreeNode* root)
    {
        if(!root) return;

        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {

        if(!root) return res;
        inorder(root);
        return res;
    }
};


//Iterative(Tutorial)
//Runtime: 0 ms
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*> S;
        TreeNode* C = root;

        while(C!=NULL || !S.empty())
        {
            while(C!=NULL)
            {
                S.push(C);
                C = C->left;
            }

            C = S.top();
            S.pop();
            res.push_back(C->val);
            C = C->right;
        }

        return res;
    }
};
