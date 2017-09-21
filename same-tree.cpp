//Runtime: 0 ms
class Solution {
public:
    bool check(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;

        if(p->val != q->val)
            return false;

        return (check(p->left, q->left) && check(p->right, q->right));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        return check(p,q);
    }
};
