// Runtime: 176 ms
// Memory Usage: 17.7 MB
class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    int count = 0;
    int res = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
      count += nums[i] == 0 ? -1 : 1;
      if (count == 0) {
        res = i + 1;
      } else if (mp.find(count) != mp.end()) {
        res = max(res, i - mp[count]);
      } else {
        mp[count] = i;
      }
    }
    return res;
  }
};