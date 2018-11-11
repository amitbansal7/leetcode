//Runtime: 24 ms
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == NULL || root->val == val) return root;

		TreeNode* l = searchBST(root->left, val);
		if (l) return l;

		TreeNode* r = searchBST(root->right, val);
		return r;
	}
};