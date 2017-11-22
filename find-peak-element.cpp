//Runtime: 6 ms
class Solution {
public:
	int binary(vector<int>&A, int lo, int hi)
	{
		if (lo == hi)
			return lo;

		int mid = lo + (hi - lo) / 2;
		if (A[mid] > A[mid + 1])
			return binary(A, lo, mid);

		return binary(A, mid + 1, hi);
	}

	int findPeakElement(vector<int>& nums) {
		return binary(nums, 0, nums.size() - 1);
	}
};
