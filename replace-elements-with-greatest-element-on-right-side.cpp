// Runtime: 56 ms
// Memory Usage: 10.7 MB
class Solution {
public:
  vector<int> replaceElements(vector<int>& arr) {
    int great = arr[arr.size() - 1];
    for (int i = arr.size() - 2; i >= 0; i--) {
      int t = arr[i];
      arr[i] = great;
      great = max(t, arr[i]);
    }
    arr[arr.size() - 1] = -1;
    return arr;
  }
};