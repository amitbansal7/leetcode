// Runtime: 60 ms
// Memory Usage: 25.6 MB
class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
    vector<vector<vector<int> > > adj(2, vector<vector<int> >(n));

    for (auto a : red_edges) {
      adj[0][a[0]].push_back(a[1]);
    }

    for (auto a : blue_edges) {
      adj[1][a[0]].push_back(a[1]);
    }


    vector<int> res;
    res.push_back(0);
    for (int i = 1; i < n; i++) {
      int dist = n * 2;
      for (int ff = 0; ff <= 1; ff++) {
        //queue<pair<src, pair<dist, color > > >
        queue<pair<int, pair<int, int> > > q;
        q.push(make_pair(0, make_pair(0, ff)));
        vector<vector<bool> > vis(2, vector<bool>(n, 0));
        vis[ff][0] = 1;

        while (!q.empty()) {

          auto t = q.front();
          q.pop();
          if (t.first == i) {
            dist = min(dist, t.second.first);
            break;
          }

          for (int a : adj[t.second.second][t.first]) {
            if (!vis[t.second.second][a]) {
              vis[t.second.second][a] = 1;
              q.push(make_pair(a, make_pair(t.second.first + 1, (t.second.second + 1) % 2 )));
            }
          }
        }

      }
      res.push_back((dist == n * 2) ? (-1) : dist);

    }
    return res;
  }
};