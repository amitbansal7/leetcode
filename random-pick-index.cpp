// Runtime: 84 ms
// Memory Usage: 18.9 MB
class Solution {
public:
  vector<int> arr;
  Solution(vector<int>& nums) {
    arr = nums;
  }

  int pick(int target) {
    int count = 0;
    for (int a : arr) {
      if (a == target) count ++;
    }
    int rd = rand() % count;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == target) {
        count--;
        if (count == rd) return i;
      }

    }
    return -1;
  }
};
