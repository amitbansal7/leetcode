//Runtime: 23 ms
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (int a : nums)
			sum += a;

		int exps = ((nums.size()) * (nums.size() + 1)) / 2;

		return exps - sum;
	}
};
