// Runtime: 268 ms
// Memory Usage: 31.9 MB
class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    set<int> st(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    vector<int> t(st.begin(), st.end());
    sort(t.begin(), t.end());
    int rank = 1;
    for (int a : t) {
      mp[a] = rank++;
    }
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = mp[arr[i]];
    }
    return arr;
  }
};