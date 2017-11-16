//Runtime: 29 ms
class Solution {
public:
    int solve(vector<vector<int> >&A, vector<vector<int> >&cache, int i, int j)
    {
        if (cache[i][j] != 0)
            return cache[i][j];

        int mx = 0;
        if (i + 1 < A.size() && A[i + 1][j] > A[i][j])
            mx = max(mx, solve(A, cache, i + 1, j));

        if (i - 1 >= 0 && A[i - 1][j] > A[i][j])
            mx = max(mx, solve(A, cache, i - 1, j));

        if (j + 1 < A[0].size() && A[i][j + 1] > A[i][j])
            mx = max(mx, solve(A, cache, i, j + 1));

        if (j - 1 >= 0 && A[i][j - 1] > A[i][j])
            mx = max(mx, solve(A, cache, i, j - 1));

        return cache[i][j] = mx + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();

        int ans = 1;
        vector<vector<int> >cache(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, solve(matrix, cache, i, j));

        return ans;
    }
};
