// Runtime: 12 ms
// Memory Usage: 10.1 MB
class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int res = 0;
		for (int i = 1; i < points.size(); i++) {
			res += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
		}
		return res;
	}
};