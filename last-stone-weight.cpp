// Runtime: 4 ms
// Memory Usage: 8.6 MB
class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue <int> pq;
    for (int a : stones) {
      pq.push(a);
    }

    while (pq.size() >= 2) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      int res = a - b;
      if (res) pq.push(res);
    }
    if (!pq.empty() && pq.top()) return pq.top();
    else return 0;
  }
};