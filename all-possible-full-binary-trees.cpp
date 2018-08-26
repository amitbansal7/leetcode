//Runtime: 80 ms
class Solution {
public:
	vector<TreeNode*> allPossibleFBT(int n) {
		vector<TreeNode*> res;
		if (n == 1) {
			res.push_back(new TreeNode(0));
			return res;
		}
		n--;
		for (int i = 1; i <= n; i += 2) {
			vector<TreeNode*> l = allPossibleFBT(i);
			vector<TreeNode*> r = allPossibleFBT(n - i);

			for (TreeNode* a : l) {
				for (TreeNode* b : r) {
					TreeNode* root = new TreeNode(0);
					root->left = a;
					root->right = b;
					res.push_back(root);
				}
			}
		}
		return res;

	}
};