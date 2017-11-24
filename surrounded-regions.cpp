//Runtime: 19 ms
class Solution {
public:

    void DFS(vector<vector<char>>&B, int i, int j)
    {
        if (i < 0 || j < 0 || i >= B.size() || j >= B[0].size() || B[i][j] != 'O')
            return;

        B[i][j] = '#';
        DFS(B, i + 1, j);
        DFS(B, i - 1, j);
        DFS(B, i, j + 1);
        DFS(B, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m <= 0)    return;
        int n = board[0].size();
        if (n <= 0)    return;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && (board[i][j] == 'O'))
                    DFS(board, i, j);


        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == '#')
                    board[i][j] = 'O';

    }
};
