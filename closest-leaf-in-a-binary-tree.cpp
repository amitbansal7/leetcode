//Runtime: 23 ms
class Solution {
public:
    unordered_map<int, vector<int> > adj;
    set<int>leafs;

    void createGraph(TreeNode* root) {
        if (!root)
            return;

        vector<int>t;
        if (adj.find(root->val) == adj.end()) {
            adj[root->val] = t;
        }

        if (!root->left && !root->right)
            leafs.insert(root->val);

        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val] = t;
            adj[root->left->val].push_back(root->val);
        }

        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val] = t;
            adj[root->right->val].push_back(root->val);
        }

        createGraph(root->left);
        createGraph(root->right);
    }

    int findClosestLeaf(TreeNode* root, int k) {
        createGraph(root);
        int src = k;
        int V = adj.size();
        unordered_map<int, bool> vis;
        unordered_map<int, int> dis;
        int mindis = INT_MAX;
        int ans;
        vis[src] = 1;
        dis[src] = 0;

        if (leafs.find(src) != leafs.end())  return k;
        queue<int> Q;
        Q.push(src);

        while (!Q.empty()) {
            int t = Q.front();
            Q.pop();
            vector<int> list = adj[t];

            for (int a : list) {
                if (vis.find(a) == vis.end()) {
                    vis[a] = 1;
                    dis[a] = dis[t] + 1;
                    if (leafs.find(a) != leafs.end()) {
                        if (dis[a] < mindis) {
                            mindis = dis[a];
                            ans = a;
                        }
                    }
                    Q.push(a);
                }
            }
        }
        return ans;
    }
};
