//Runtime: 23 ms
class Solution {
public:

    typedef struct
    {
        int n;
        vector<int>parent;
        vector<int>rank;
    }Set;

    Set* NewSet(int n)
    {
        Set* S = new Set;
        S->n = n;
        vector<int> p;

        for(int i=0;i<n;i++)
            p.push_back(i);

        vector<int> r(n, 0);
        S->parent = p;
        S->rank = r;
        return S;
    }

    int find(int p, Set* S)
    {
        if(p != S->parent[p])
            S->parent[p] = find(S->parent[p], S);

        return S->parent[p];
    }

    void merge(int x,int y, Set *S)
    {
        if(S->rank[x] > S->rank[y])
            S->parent[y] = x;
        else
            S->parent[x] = y;

        if(S->rank[x] == S->rank[y])
            S->rank[y]++;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if(n == 0)
            return 0;

        Set* S = NewSet(n);
        set<int> P;
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                if(M[i][j])
                {
                    P.insert(i);
                    P.insert(j);
                }

        int ans = P.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(M[i][j])
                {
                    int x = find(i, S);
                    int y = find(j, S);

                    if(x!=y)
                    {
                        merge(x,y, S);
                        ans--;
                    }
                }
            }
        return ans;
    }
};
