//Runtime: 3 ms
class Solution {
public:

    int liveNeighbors(vector<vector<int> >&b, int i, int j) {
        int res = 0;
        res += i + 1 < b.size() ? (b[i + 1][j] & 1) : 0;
        res += i - 1 >= 0 ? (b[i - 1][j] & 1) : 0;
        res += (i + 1 < b.size() && j + 1 < b[0].size()) ? (b[i + 1][j + 1] & 1) : 0;
        res += (i - 1 >= 0 && j + 1 < b[0].size()) ? (b[i - 1][j + 1] & 1) : 0;
        res += j + 1 < b[0].size() ? (b[i][j + 1] & 1) : 0;
        res += j - 1 >= 0 ? (b[i][j - 1] & 1) : 0;
        res += (i - 1 >= 0 && j - 1 >= 0) ? (b[i - 1][j - 1] & 1) : 0;
        res += (i + 1 < b.size() && j - 1 >= 0) ? (b[i + 1][j - 1] & 1) : 0;
        return res;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int lives = liveNeighbors(board, i, j);
                if (board[i][j] == 1 && lives >= 2 && lives <= 3) {
                    board[i][j] = 3;
                }
                else if (board[i][j] == 0 && lives == 3) {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};
