//Runtime: 16 ms
class Solution {
public:

    int f = 1;
    void TopSort(int src, int visited[],int greyset[], stack<int> &S, vector<int>adj[])
    {
        visited[src] = 1;
        greyset[src]= 1;

        for(auto it:adj[src])
        {
            if(!visited[it])
                TopSort(it, visited, greyset, S, adj);
            else
            {
                if(greyset[it])
                    f = 0;
            }
        }

        greyset[src] = 0;
        S.push(src);
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int>adj[numCourses];

        vector<pair<int,int> > ::iterator it;
        for(it=prerequisites.begin();it!=prerequisites.end();it++)
            adj[it->second].push_back(it->first);

        stack<int>S;
        int visited[numCourses];
        memset(visited, 0, sizeof(visited));

        int greyset[numCourses];
        memset(greyset, 0, sizeof(greyset));

        for(int i=0;i<numCourses;i++)
            if(!visited[i])
                TopSort(i, visited, greyset, S, adj);

        vector<int> res;
        if(!f)
            return res;

        while(!S.empty())
        {
            res.push_back(S.top());
            S.pop();
        }

        return res;

    }
};
