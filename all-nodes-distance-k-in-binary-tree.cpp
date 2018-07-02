//Runtime: 7 ms
class Solution {
public:

	void toGraph(TreeNode* root, map<int, vector<int> >&adj) {
		vector<int> t;
		if (root->left) {
			adj[root->val].push_back(root->left->val);
			adj[root->left->val].push_back(root->val);
			toGraph(root->left, adj);
		}
		if (root->right) {
			adj[root->val].push_back(root->right->val);
			adj[root->right->val].push_back(root->val);
			toGraph(root->right, adj);
		}

	}

	void dfs(map<int, vector<int> >&adj, int tar, int dis, vector<int> &res, set<int> &vis) {
		if (vis.find(tar) != vis.end()) return;
		if (dis == 0)    res.push_back(tar);
		if (dis <= 0) return;

		if (vis.find(tar) == vis.end()) {
			vis.insert(tar);

			for (int a : adj[tar]) {
				dfs(adj, a, dis - 1, res, vis);
			}
		}

	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		map<int, vector<int> > adj;

		toGraph(root, adj);

		vector<int> res;
		set<int> vis;
		dfs(adj, target->val, K, res, vis);
		return res;
	}
};