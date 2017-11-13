//Runtime: 16 ms
class Solution {
public:
	TreeNode* solve(vector<int>&inorder, vector<int>& postorder, int is, int ie, int *pe)
	{
		if (is > ie)
			return NULL;
		int t = 0;
		TreeNode* root = new TreeNode(postorder[*pe]);
		for (int i = is; i <= ie; i++)
			if (inorder[i] == root->val)
			{
				t = i;
				break;
			}
		(*pe)--;
		root->right = solve(inorder, postorder, t + 1, ie, pe);
		root->left = solve(inorder, postorder, is, t - 1, pe);

		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = postorder.size() - 1;
		return solve(inorder, postorder, 0, n, &n);
	}
};
