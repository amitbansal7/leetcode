//Runtime: 6 ms
class Solution {
public:
    int ans = 0;

    bool isSafe(vector<string> &B, int x, int y)
    {
        for(int i=0;i<x;i++)
            for(int j=0;j<B.size();j++)
                if(B[i][j] == 'Q' && (y == j || x + y == i+j || x + j == i + y))
                    return 0;
        return 1;
    }

    void solve(vector<string>&B, int i)
    {
        if(i>=B.size())
        {
            ans++;
            return;
        }

        for(int j=0;j<B.size();j++)
        {
            if(isSafe(B, i, j))
            {
                B[i][j] = 'Q';
                solve(B, i+1);
                B[i][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        string s = "";
        for(int i=0;i<n;i++)
            s += '.';

        vector<string> B(n, s);

        solve(B, 0);
        return ans;
    }
};
