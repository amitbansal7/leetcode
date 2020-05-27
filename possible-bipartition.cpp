// Runtime: 432 ms
// Memory Usage: 72.5 MB
class Solution {
public:

	bool solve(vector<vector<int> > &adj, vector<bool> &vis, vector<int> &group, int src) {
		bool res = true;
		int nextGrp = (group[src] + 1) % 2;
		for (int a : adj[src]) {
			if (vis[a] && group[a] == group[src]) {
				return false;
			}
			if (!vis[a]) {
				group[a] = nextGrp;
				vis[a] = true;
				if (!solve(adj, vis, group, a)) {
					return false;
				}
			}
		}
		return true;
	}

	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		vector<vector<int> > adj(N + 1);
		for (auto a : dislikes) {
			adj[a[0]].push_back(a[1]);
			adj[a[1]].push_back(a[0]);
		}
		vector<bool> vis(N + 1, 0);
		vector<int> group(N + 1, -1);
		for (int i = 1; i <= N; i++) {
			if (!vis[i]) {
				group[i] = 0;
				if (!solve(adj, vis, group, i)) {
					return false;
				}
			}
		}
		return true;
	}
};