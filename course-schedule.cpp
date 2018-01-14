//Runtime: 12 ms
class Solution {
public:
    int f = 1;
    void DFS(int src, int visited[], int greyset[],vector<int> adj[])
    {
        visited[src] = 1;
        greyset[src] = 1;
        vector<int> ::iterator it;
        for(it=adj[src].begin();it!=adj[src].end();it++)
        {
            if(!visited[*it])
                DFS(*it, visited, greyset, adj);

            else
            {
                if(greyset[*it])
                    f = 0;
            }

        }
        greyset[src] = 0;
    }

    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {

        vector<int>adj[numCourses];

        vector<pair<int,int> > ::iterator ct;
        for(ct=prerequisites.begin();ct!=prerequisites.end();ct++)
            adj[ct->first].push_back(ct->second);

        int visited[numCourses];
        int greyset[numCourses];
        memset(visited, 0, sizeof(visited));
        memset(greyset, 0, sizeof(greyset));

        for(int i=0;i<numCourses;i++)
            if(!visited[i])
                DFS(i, visited, greyset, adj);

        return f;

    }
};
