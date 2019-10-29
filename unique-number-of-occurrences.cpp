// Runtime: 4 ms
// Memory Usage: 9 MB
class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (int a : arr) {
      mp[a]++;
    }
    unordered_set<int> st;
    for (auto a : mp) {
      if (st.find(a.second) != st.end()) {
        return false;
      }
      st.insert(a.second);
    }
    return true;
  }
};