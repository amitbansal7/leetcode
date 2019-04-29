// Runtime: 8 ms
// Memory Usage: 9.3 MB
class Solution {
public:

  static bool compare(vector<int> &a, vector<int> &b) {
    return (a[0] - a[1] < b[0] - b[1]);
  }

  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(), compare);
    int n = costs.size() / 2;
    int cost = 0;

    for (int i = 0; i < costs.size(); i++) {
      int idx = (i < n) ? 0 : 1;
      cost += costs[i][idx];
    }
    return cost;
  }
};