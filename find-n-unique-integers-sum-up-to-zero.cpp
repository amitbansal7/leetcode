// Runtime: 4 ms
// Memory Usage: 8.7 MB
class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> res;
		res.push_back(0);
		for (int i = 1; i < n; i++) {
			res[0] -= i;
			res.push_back(i);
		}
		return res;
	}
};