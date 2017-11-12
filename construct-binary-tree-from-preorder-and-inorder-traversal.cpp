//Runtime: 22 ms
class Solution {
public:
	TreeNode* solve(vector<int>&preorder, vector<int>&inorder, int rt, int is, int je)
	{
		if (rt > preorder.size() - 1 || is > je)
			return NULL;

		TreeNode* root = new TreeNode(preorder[rt]);
		int t = 0;
		for (int i = is; i <= je; i++)
			if (inorder[i] == preorder[rt])
			{
				t = i;
				break;
			}
		root->left = solve(preorder, inorder, rt + 1, is, t - 1);
		root->right = solve(preorder, inorder, rt + t + 1 - is, t + 1, je);
		return root;

	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return solve(preorder, inorder, 0, 0, inorder.size() - 1);
	}
};
