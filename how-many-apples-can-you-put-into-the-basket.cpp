// Runtime: 4 ms
// Memory Usage: 8.9 MB
class Solution {
public:
  int maxNumberOfApples(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int sum = 0;
    int i;
    for (i = 0; i < arr.size(); i++) {
      if (sum + arr[i] <= 5000) {
        sum += arr[i];
      } else {
        break;
      }
    }
    return i;
  }
};