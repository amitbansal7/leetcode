//(Learned from discus section)
//Runtime: 26 ms
//Iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(1)
        {
            if(root->val > p->val && root->val > q->val)
                root = root->left;
            else if(root->val < p->val && root->val < q->val)
                root = root->right;
            else
                return root;
        }
    }
};

//Runtime: 33 ms
//Recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
