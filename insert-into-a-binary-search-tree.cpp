//Runtime: 52 ms
class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == NULL)
			root = new TreeNode(val);
		else if (root->val > val)
			root->left = insertIntoBST(root->left, val);
		else
			root->right = insertIntoBST(root->right, val);

		return root;
	}
};