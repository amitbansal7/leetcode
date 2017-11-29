//Runtime: 6 ms
class Solution {
public:
    struct Set
    {
        int v;
        vector<int>parent;
        vector<int>rank;
    };

    int find(struct Set* S, int u)
    {
        if (S->parent[u] != u)
            S->parent[u] = find(S, S->parent[u]);

        return S->parent[u];
    }

    void Union(struct Set* S, int x, int y)
    {
        if (S->rank[x] > S->rank[y])
            S->parent[y] = x;
        else
            S->parent[x] = y;

        if (S->rank[x] == S->rank[y])
            S->rank[x]++;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int v = edges.size();

        struct Set* S = new Set();

        S->v = v + 1;
        S->parent.push_back(0);
        S->rank.push_back(0);
        for (int i = 1; i <= v; i++)
        {
            S->parent.push_back(i);
            S->rank.push_back(0);
        }

        vector<int>res;
        for (vector<int> vec : edges)
        {
            int x = find(S, vec[0]);
            int y = find(S, vec[1]);

            if (x == y)
            {
                res.clear();
                res.push_back(vec[0]);
                res.push_back(vec[1]);
            }
            else
                Union(S, x, y);
        }
        return res;
    }
};
