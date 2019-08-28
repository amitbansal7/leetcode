// Runtime: 12 ms
// Memory Usage: 10.2 MB
class Solution {
public:

  int getIdx(int &n, int i, int j, int k) {
    return (i * n + j) * 4 + k;
  }

  int find(int f, vector<int> &parent) {
    if (f != parent[f]) {
      parent[f] = find(parent[f], parent);
    }
    return parent[f];
  }

  void _union(int x, int y, vector<int>&parent, vector<int>&rank) {
    int px = find(x, parent);
    int py = find(y, parent);

    if (rank[x] > rank[y]) {
      parent[py] = px;
    } else {
      parent[px] = py;
    }
    if (rank[x] == rank[y]) {
      rank[y]++;
    }
  }


  int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    int size = n * n * 4;
    vector<int> parent(size);
    vector<int> rank(size, 1);
    for (int i = 0; i < size; i++) {
      parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i > 0) _union(getIdx(n, i - 1, j, 2), getIdx(n, i, j, 0), parent, rank);
        if (j > 0) _union(getIdx(n, i, j - 1, 1), getIdx(n, i, j, 3), parent, rank);
        // if (i + 1 < n) _union(getIdx(n, i + 1, j, 0), getIdx(n, i, j, 2), parent, rank);
        // if (j + 1 < n) _union(getIdx(n, i, j + 1, 3), getIdx(n, i, j, 1), parent, rank);

        // ' ' or '\\'
        if (grid[i][j] != '/') {
          _union(getIdx(n, i, j, 0), getIdx(n, i, j, 1), parent, rank);
          _union(getIdx(n, i, j, 2), getIdx(n, i, j, 3), parent, rank);
        }

        // ' ' or '/'
        if (grid[i][j] != '\\') {
          _union(getIdx(n, i, j, 0), getIdx(n, i, j, 3), parent, rank);
          _union(getIdx(n, i, j, 1), getIdx(n, i, j, 2), parent, rank);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < size; i++) {
      if (find(i, parent) == i) {
        res++;
      }
    }
    return res;
  }
};