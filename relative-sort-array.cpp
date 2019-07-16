// Runtime: 4 ms
// Memory Usage: 9.3 MB
class Solution {
public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> idx;
    for (int i = 0; i < arr2.size(); i++)
      idx[arr2[i]] = i;

    vector<vector<int> >arrs(idx.size());
    vector<int> notIn2;

    for (int a : arr1) {
      if (idx.find(a) != idx.end()) {
        arrs[idx[a]].push_back(a);
      } else {
        notIn2.push_back(a);
      }
    }

    sort(notIn2.begin(), notIn2.end());
    vector<int> res;

    for (auto a : arrs) res.insert(res.end(), a.begin(), a.end());
    res.insert(res.end(), notIn2.begin(), notIn2.end());
    return res;
  }
};