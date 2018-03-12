//Runtime: 88 ms
class Solution {
public:
	void solve(vector<vector<int>>&adj, vector<vector<int>>&res, vector<int> &t, int src, vector<bool> &vis) {
		if (src == adj.size() - 1) {
			res.push_back(t);
			return;
		}
		vis[src] = 1;

		for (int a : adj[src]) {
			t.push_back(a);
			solve(adj, res, t, a, vis);
			t.pop_back();
		}
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int v = graph.size();
		vector<bool>vis(v, 0);
		vector<vector<int>> res;
		vector<int> t;
		t.push_back(0);
		solve(graph, res, t, 0, vis);
		return res;
	}
};