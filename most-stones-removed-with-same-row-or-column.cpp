//Runtime: 24 ms
class Solution {
public:

    class Set {
    public:
        int v;
        vector<int> parent;
        vector<int> rank;

        Set(int n) {
            v = n;
            for (int i = 0; i < n; i++) {
                rank.push_back(0);
                parent.push_back(i);
            }
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unionS(int x, int y) {
            if (rank[x] > rank[y]) {
                parent[find(y)] = find(x);
            } else {
                parent[find(x)] = find(y);
            }

            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    };

    int removeStones(vector<vector<int>>& stones) {

        Set *s = new Set(20000);

        for (auto a : stones) {
            s->unionS(a[0], 10000 + a[1]);
        }

        set<int> parents;

        for (auto a : stones) {
            parents.insert(s->find(a[0]));
        }
        return stones.size() - parents.size();
    }
};