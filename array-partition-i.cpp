//Runtime: 76 ms
class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i % 2 == 0) {
				res += nums[i];
			}
		}
		return res;
	}
};