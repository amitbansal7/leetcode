//Runtime: 68 ms
class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (root == NULL) return 0;
		int cur = (root->val >= L && root->val <= R) ? root->val : 0;

		return cur + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
	}
};