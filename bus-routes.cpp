//Runtime: 84 ms
class Solution {
public:

    int binary(vector<int> a, int f){
        int lo = 0;
        int hi = a.size()-1;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(a[mid] == f){
                return mid;
            }else if(a[mid] > f){
                hi = mid -1;
            }else{
                lo = mid +1;
            }
        }
        return -1;
    }

    bool isConnected(vector<int> a, vector<int> b){
        int i = 0;
        int j = 0;

        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                return 1;
            }

            if(a[i] < b[j]) i++;
            else j++;
        }
        return 0;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        vector<vector<int> >adj(routes.size());
        if(S == T){
            return 0;
        }
        for(auto a:routes){
            sort(a.begin(), a.end());
        }

        for(int i=0;i<routes.size();i++){
            for(int j=i+1;j<routes.size();j++){

                if(isConnected(routes[i], routes[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        set<int> targetRoutes;
        queue<pair<int, int> > q;
        set<int> vis;

        for(int i=0;i<routes.size();i++){
            if(binary(routes[i], S) != -1){
                q.push(make_pair(i, 1));
                vis.insert(i);
            }
            if(binary(routes[i], T) != -1){
                targetRoutes.insert(i);
            }
        }

        while(!q.empty()){

            pair<int, int> t = q.front();
            q.pop();

            if(targetRoutes.find(t.first) != targetRoutes.end()){
                return t.second;
            }

            for(int a: adj[t.first]){
                if(vis.find(a) == vis.end()){
                    vis.insert(a);
                    q.push(make_pair(a, t.second+1));
                }
            }
        }
        return -1;
    }

};