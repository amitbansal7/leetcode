//Runtime: 103 ms
class Solution {
public:
	bool al, pac;

	void dfs(vector<vector<int> >&m, vector<vector<int> >&vis, int i, int j, int prev) {
		if (i < 0 || j < 0 || i >= m.size() || j >= m[0].size() || m[i][j] > prev  || (al && pac))
			return;

		if (i == 0 || j == 0 || vis[i][j] == 3 || vis[i][j] == 1)
			pac = true;

		if (i == m.size() - 1 || j == m[0].size() - 1 || vis[i][j] == 3 || vis[i][j] == 2)
			al = true;

		if (vis[i][j] != -1) {
			return;
		}

		prev = m[i][j];
		m[i][j] = INT_MAX;

		dfs(m, vis, i - 1, j, prev);
		dfs(m, vis, i, j - 1, prev);
		dfs(m, vis, i + 1, j, prev);
		dfs(m, vis, i, j + 1, prev);

		m[i][j] = prev;
	}

	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int> >res;
		int m = matrix.size();
		if (m == 0)
			return res;
		int n = matrix[0].size();
		vector<vector<int > >vis(m, vector<int>(n, -1));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				al = pac = false;
				dfs(matrix, vis, i, j, INT_MAX);
				if (al && pac) {
					res.push_back(make_pair(i, j));
					vis[i][j] = 3;
				} else {
					if (pac)
						vis[i][j] = 1;
					else if (al)
						vis[i][j] = 2;
				}
			}
		}
		return res;
	}
};

//Runtime: 47 ms
class Solution {
public:

	void dfs(vector<vector<int> >&m, int i, int j, vector<vector<bool> >&vis, int prev) {
		if (i < 0 || j < 0 || i >= m.size() || j >= m[0].size() || m[i][j] < prev || vis[i][j])
			return;

		vis[i][j] = 1;
		prev = m[i][j];
		m[i][j] = INT_MIN;
		dfs(m, i + 1, j, vis, prev);
		dfs(m, i - 1, j, vis, prev);
		dfs(m, i, j + 1, vis, prev);
		dfs(m, i, j - 1, vis, prev);
		m[i][j] = prev;
	}

	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int> >res;
		int m = matrix.size();
		if (m == 0)
			return res;
		int n = matrix[0].size();

		vector<vector<bool> >pac(m, vector<bool>(n, 0));
		vector<vector<bool> > atl = pac;

		for (int i = 0; i < m; i++) {
			dfs(matrix, i, 0, pac, INT_MIN);
			dfs(matrix, i, n - 1, atl, INT_MIN);
		}

		for (int j = 0; j < n; j++) {
			dfs(matrix, 0, j, pac, INT_MIN);
			dfs(matrix, m - 1, j, atl, INT_MIN);
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (pac[i][j] && atl[i][j])
					res.push_back(make_pair(i, j));
			}
		}
		return res;
	}
};
