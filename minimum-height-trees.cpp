//Runtime: 36 ms
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

        vector<int>res;
        if(n==1)
        {
            res.push_back(0);
            return res;
        }

        vector<int> adj[n];
        vector<pair<int, int> > ::iterator it;
        for(it=edges.begin();it!=edges.end();it++)
        {
            adj[it->first].push_back(it->second);
            adj[it->second].push_back(it->first);

        }

        vector<int>leaf;

        if(n==1)
        {
            leaf.push_back(0);
            return leaf;
        }

        for(int i=0;i<n;i++)
            if(adj[i].size() == 1)
                leaf.push_back(i);

        while(1)
        {
            vector<int> next;
            for(int n : leaf)
                for(int nbr : adj[n])
                {
                    adj[nbr].erase(remove(adj[nbr].begin(), adj[nbr].end(), n), adj[nbr].end());
                    if(adj[nbr].size() == 1)
                        next.push_back(nbr);
                }
            if(next.empty())
                return leaf;
            leaf = next;
        }
    }
};
