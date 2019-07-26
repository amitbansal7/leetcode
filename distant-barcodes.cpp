// Runtime: 236 ms
// Memory Usage: 21.8 MB
class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    map<int, int> mp;
    for (int a : barcodes) mp[a]++;

    typedef pair<int, int> pii;
    priority_queue<pii, vector<pii> > pq;


    for (auto a : mp) {
      pq.push({a.second, a.first});
    }
    int pos = 0;
    while (!pq.empty()) {
      auto a = pq.top();
      pq.pop();
      for (int i = 0; i < a.first; i++) {
        if (pos >= barcodes.size()) pos = 1;
        barcodes[pos] = a.second;
        pos += 2;
      }
    }

    return barcodes;
  }
};