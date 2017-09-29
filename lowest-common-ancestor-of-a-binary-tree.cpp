//Learned form
//Runtime: 13 ms
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root;
        if(!left && !right) return NULL;

        return left?left:right;
    }
};

/*
    My solution
    -Not Accepted-
    Another approach..
    output :- Memory Limit Exceeded
    29 / 31 test cases passed.
*/
class Solution {
public:
    stack<TreeNode*> PS;
    stack<TreeNode*> QS;

    void solve(TreeNode* root, TreeNode *p, TreeNode* q, stack<TreeNode*> S)
    {
        if(!root)
            return;

        S.push(root);

        if(root == p)
            PS = S;
        else if(root == q)
            QS = S;

        solve(root->left, p, q, S);
        solve(root->right, p, q, S);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        stack<TreeNode*> S;
        solve(root, p, q, S);

        while(!PS.empty())
        {
            stack<TreeNode*> TQS;
            TQS = QS;

            TreeNode* find = PS.top();
            PS.pop();

            while(!TQS.empty())
            {
                if(TQS.top() == find)
                    return find;
                TQS.pop();
            }
        }

        return NULL;
    }
};
