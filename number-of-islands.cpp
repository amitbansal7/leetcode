//Using Union Find
//Runtime: 26 ms
class Solution {
public:

    typedef struct
    {
        int m,n;
        vector<vector<pair<int,int> > > parent;
        vector<vector<int> > rank;
    }Set;

    Set* NewSet(int m, int n)
    {
        Set* set = new Set;
        set->m = m;
        set->n = n;
        vector<vector<int > >ra(m, vector<int>(n, 0));
        set->rank = ra;
        vector<vector<pair<int,int> > > pa;

        for(int i=0;i<m;i++)
        {
            vector<pair<int,int> > P;
            for(int j=0;j<n;j++)
                P.push_back(make_pair(i,j));
            pa.push_back(P);
        }

        set->parent = pa;

        return set;
    }

    pair<int,int> find(Set* S, pair<int,int> P)
    {
        if(P != S->parent[P.first][P.second])
            S->parent[P.first][P.second] = find(S, S->parent[P.first][P.second]);

        return S->parent[P.first][P.second];
    }

    void Union(pair<int,int> P, pair<int,int> Q, Set* S)
    {
        if(S->rank[P.first][P.second] > S->rank[Q.first][Q.second])
            S->parent[Q.first][Q.second] = P;
        else
            S->parent[P.first][P.second] = Q;

        if(S->rank[P.first][P.second] == S->rank[Q.first][Q.second])
            S->rank[Q.first][Q.second]++;
    }

    int numIslands(vector<vector<char> >& grid) {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();
        if(n==0)
            return 0;

        Set* S = NewSet(m,n);
        int ans = 0;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == '1')
                    ans++;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] != '1')   continue;


                if(i>0 && grid[i-1][j] == '1')
                {
                    pair<int,int> pr = find(S, make_pair(i,j));
                    pair<int,int> T = find(S, make_pair(i-1, j));
                    if(pr!= T)
                    {
                        ans--;
                        Union(pr, T, S);
                    }
                }
                if(i+1<m && grid[i+1][j] == '1')
                {
                    pair<int,int> pr = find(S, make_pair(i,j));
                    pair<int,int> T = find(S, make_pair(i+1, j));
                    if(pr != T)
                    {
                        ans--;
                        Union(pr, T, S);
                    }
                }

                if(j>0 && grid[i][j-1] == '1')
                {
                    pair<int,int> pr = find(S, make_pair(i,j));
                    pair<int,int> T = find(S, make_pair(i, j-1));
                    if(pr != T)
                    {
                        ans--;
                        Union(pr, T, S);

                    }
                }

                if(j+1 < n && grid[i][j+1] == '1')
                {
                    pair<int,int> pr = find(S, make_pair(i,j));
                    pair<int,int> T = find(S, make_pair(i, j+1));
                    if(pr != T)
                    {
                        ans--;
                        Union(pr, T, S);
                    }
                }
            }
        }

        return ans;

    }
};

//Runtime: 12 ms
class Solution {
public:

    void solve(vector<vector<char> >&grid, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()|| grid[i][j]=='0')
            return;

        grid[i][j] = '0';
        solve(grid, i+1, j);
        solve(grid, i-1, j);
        solve(grid, i, j-1);
        solve(grid, i, j+1);
    }

    int numIslands(vector<vector<char> >& grid) {

        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    solve(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
