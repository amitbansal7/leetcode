// Runtime: 604 ms
// Memory Usage: 78.4 MB
class Solution {
public:
  double dist(vector<int> p) {
    int x1 = (double)p[0];
    int x2 = (double)p[1];
    return sqrt(pow(x2, 2) + pow(x1, 2));
  }
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<double, vector<int> >, vector<pair<double, vector<int> > >, greater<pair<double, vector<int> > > >pq;

    for (auto p : points) {
      pq.push({dist(p), p});
    }
    vector<vector<int> > res;
    while (K-- && !pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
  }
};