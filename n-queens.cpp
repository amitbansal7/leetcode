//Runtime: 6 ms
class Solution {
public:

    bool isSafe(vector<string> &B, int x, int y)
    {
        for (int i = 0; i < x; i++)
            for (int j = 0; j < B.size(); j++)
                if (B[i][j] == 'Q' && (y == j || x + y == i + j || x + j == y + i))
                    return 0;
        return 1;
    }

    void solve(vector<string>&B, vector<vector<string> > &res, int i)
    {
        if (i >= B.size())
        {
            res.push_back(B);
            return;
        }
        for (int j = 0; j < B.size(); j++)
        {
            if (isSafe(B, i, j))
            {
                B[i][j] = 'Q';
                solve(B, res, i + 1);
                B[i][j] = '.';
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        string s = "";
        for (int i = 0; i < n; i++)
            s += '.';

        vector<string> B(n, s);
        solve(B, res, 0);
        return res;
    }
};
