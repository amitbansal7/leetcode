//Runtime: 16 ms
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<long long int> s;

		if (k < 1)
			return false;

		for (int i = 0; i < nums.size(); i++) {
			auto it = s.lower_bound((long long int)nums[i] - t);
			if (it != s.end() && *it <= (long long int)nums[i] + t)
				return 1;

			s.insert(nums[i]);
			if (i >= k) {
				s.erase(nums[i - k]);
			}
		}
		return false;
	}
};
