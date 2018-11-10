//Runtime: 60 ms
class Solution {
public:

	void solve(vector<int> &res, Node* root) {
		res.push_back(root->val);
		for (Node* ch : root->children) {
			solve(res, ch);
		}
	}

	vector<int> preorder(Node* root) {
		vector<int> res;
		if (root != NULL) {
			solve(res, root);
		}
		return res;
	}
};