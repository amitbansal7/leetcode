//Runtime: 154 ms
class Solution {
public:

	bool dfs(vector<vector<int>>&adj, int src, vector<int> &vis) {
		if (vis[src] == 1)
			return 0;
		if (vis[src] == 2)
			return 1;

		vis[src] = 1;

		for (int a : adj[src]) {
			if (vis[a] == 1 || !dfs(adj, a, vis))
				return false;
		}
		vis[src] = 2;
		return true;
	}

	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int v = graph.size();

		vector<int>vis(v + 1, 0);
		vector<int> res;
		for (int i = 0; i < v; i++) {
			if (dfs(graph, i, vis))
				res.push_back(i);
		}

		return res;
	}
};