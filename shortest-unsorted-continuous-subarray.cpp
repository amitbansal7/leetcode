//Runtime: 28 ms
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		stack<int> ls, rs;
		int l = nums.size(), r = 0;

		for (int i = 0, j = nums.size() - 1; i < nums.size(), j >= 0; i++, j--) {

			while (!ls.empty() && nums[ls.top()] > nums[i]) {
				l = min(l, ls.top());
				ls.pop();
			}

			while (!rs.empty() && nums[rs.top()] < nums[j]) {
				r = max(r, rs.top());
				rs.pop();
			}

			ls.push(i);
			rs.push(j);

		}

		if (r - l > 0) {
			return r - l + 1;
		} else return 0;

	}
};