//Runtime: 19 ms
class Solution {
public:

    bool isOk(vector<vector<char> >&B, int x, int y, char n)
    {
        for (int i = 0; i < B.size(); i++)
            if (B[i][y] == n)
                return 0;

        for (int i = 0; i < B.size(); i++)
            if (B[x][i] == n)
                return 0;

        int rs = x - x % 3;
        int cs = y - y % 3;
        for (int i = rs; i < rs + 3; i++)
            for (int j = cs; j < cs + 3; j++)
                if (B[i][j] == n)
                    return 0;
        return 1;
    }

    bool solve(vector<vector<char > >&B)
    {
        for (int i = 0; i < B.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                if (B[i][j] == '.')
                {
                    for (char n = '1'; n <= '9'; n++)
                    {
                        if (isOk(B, i, j, n))
                        {
                            B[i][j] = n;

                            if (solve(B))
                                return 1;
                            else
                                B[i][j] = '.';
                        }
                    }
                    return 0;
                }
            }

        }
        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() == 0)
            return;

        solve(board);
    }
};
