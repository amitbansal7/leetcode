//Runtime: 153 ms
class Solution {
private:

    int parent[10002];
    int rank[10002];

    int find(int u){
        if(u != parent[u]){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void DJunion(int x, int y){
        int fx = find(x);
        int fy = find(y);

        if(fx != fy){
            if(rank[fx] > rank[fy]){
                parent[fy] = fx;
            }else{
                parent[fx] = fy;
            }

            if(rank[fx] == rank[fy]){
                rank[fy]++;
            }
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i=0;i<=10001;i++){
            parent[i] = i;
            rank[i] = 0;
        }
        map<string, string> emailToName;
        map<string, int>emailToId;
        int id = 1;
        for(auto acc:accounts){
            for(int i=1;i<acc.size();i++){
                emailToName[acc[i]] = acc[0];
                if(emailToId.find(acc[i]) == emailToId.end()){
                    emailToId[acc[i]] = id++;
                }
                DJunion(emailToId[acc[i]], emailToId[acc[1]]);
            }
        }
        map<int, vector<string> > res;

        for(auto email:emailToName){
            int id = find(emailToId[email.first]);
            res[id].push_back(email.first);
        }

        vector<vector<string> >ans;
        for(auto temp:res){
            vector<string> t = temp.second;
            sort(t.begin(), t.end());
            string name = emailToName[t[0]];
            t.insert(t.begin(), name);
            ans.push_back(t);
        }

        return ans;

    }
};


//Runtime: 539 ms
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> emailToName;
        map<string, set<string> > adj;

        for (auto acc : accounts) {
            for (int i = 1; i < acc.size(); i++) {
                for (int j = i; j < acc.size(); j++) {
                    adj[acc[i]].insert(acc[j]);
                    adj[acc[j]].insert(acc[i]);
                }
                emailToName[acc[i]] = acc[0];
            }
        }
        vector<vector<string> > res;
        set<string> vis;

        for (auto bin : adj) {
            if (vis.find(bin.first) == vis.end()) {
                queue<string> Q;
                Q.push(bin.first);
                vector<string> t;
                vis.insert(bin.first);
                while (!Q.empty()) {
                    auto em = Q.front();
                    Q.pop();
                    t.push_back(em);
                    for (auto a : adj[em]) {
                        if (vis.find(a) == vis.end()) {
                            Q.push(a);
                            vis.insert(a);
                        }
                    }
                }
                sort(t.begin(), t.end());
                t.insert(t.begin(), emailToName[t[0]]);
                res.push_back(t);
            }
        }
        return res;

    }
};
