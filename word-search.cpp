//Runtime: 19 ms
class Solution {
public:
    bool ans = 0;
    int m;
    int n;

    void solve(vector<vector<char> >&B, string &word,int i, int j, int p, int q, int k)
    {
        if(k >= word.size())
            ans = 1;

        if(i<0 || i >= m || j<0 || j>= n || k >= word.size())
            return;
        char c;
        if(B[i][j] == word[k])
        {
            c = B[i][j];
            B[i][j] = '$';
            if(k == word.size()-1)
            {
                ans = 1;
                return;
            }
        }
        else
            return;

        if(!ans && i+1 < m && (i+1 != p || j!=q) && B[i+1][j] != '$')
            solve(B, word, i+1, j, i, j, k+1);

        if(!ans && j+1 < n && (i!=p || j+1!=q) && B[i][j+1] != '$')
            solve(B, word, i, j+1, i, j, k+1);

        if(!ans && i-1>=0 && (i-1!=p || j!=p) && B[i-1][j] != '$')
            solve(B, word, i-1, j, i, j, k+1);

        if(!ans && j-1>=0 && (j-1!=q || i!=p) && B[i][j-1] != '$')
            solve(B, word, i, j-1, i, j, k+1);

        B[i][j] = c;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0])
                    solve(board, word, i, j, i, j, 0);
                if(ans)
                    return ans;
            }

        return ans;
    }
};
