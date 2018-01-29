//Runtime: 28 ms
class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		set<int>s;
		int sum = 0, prev = 0, mod;
		for (int a : nums) {
			sum += a;
			mod = k == 0 ? sum : sum % k;
			if (s.find(mod) != s.end())
				return true;
			s.insert(prev);
			prev = mod;
		}
		return false;
	}
};
