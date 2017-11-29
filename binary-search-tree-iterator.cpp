//Runtime: 19 ms
class BSTIterator {
public:
	stack<TreeNode*>S;
	BSTIterator(TreeNode *root) {
		while (root)
		{
			S.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !S.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* t = S.top();
		int ans = t->val;
		S.pop();

		if (t->right)
		{
			t = t->right;
			while (t)
			{
				S.push(t);
				t = t->left;
			}
		}
		return ans;
	}
};
