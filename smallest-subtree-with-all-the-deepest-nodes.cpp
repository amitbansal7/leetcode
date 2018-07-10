//Runtime: 4 ms
class Solution {
public:

	pair<TreeNode*, int> dfs(TreeNode* root, int d) {
		if (root == NULL) return make_pair(root, 0);

		pair<TreeNode*, int> l = dfs(root->left, d);
		pair<TreeNode*, int> r = dfs(root->right, d);

		if (l.second == r.second) {
			return make_pair(root, l.second + 1);
		} else if (l.second > r.second) {
			return make_pair(l.first, l.second + 1);
		} else {
			return make_pair(r.first, r.second + 1);;
		}
	}

	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		return dfs(root, 0).first;
	}
};