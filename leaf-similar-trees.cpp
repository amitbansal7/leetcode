//Runtime: 0 ms
class Solution {
public:

    void leafs(TreeNode* root, vector<int> &l) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            l.push_back(root->val);
        }

        leafs(root->left, l);
        leafs(root->right, l);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> one;
        vector<int> two;
        leafs(root1, one);
        leafs(root2, two);
        return one == two;
    }
};