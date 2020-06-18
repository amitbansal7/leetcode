// Runtime: 40 ms
// Memory Usage: 18.7 MB
class Solution {
public:
	int hIndex(vector<int>& citations) {
		int lo = 0;
		int hi = citations.size() - 1;
		int res = 0;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			int count = citations.size() - mid;
			if (citations[mid] >= count) {
				res = max(res, count);
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		return res;
	}
};