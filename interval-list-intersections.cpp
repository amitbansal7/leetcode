// Runtime: 64 ms
// Memory Usage: 18.8 MB
class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>> res;
		int i = 0;
		int j = 0;
		while (i < A.size() && j < B.size()) {
			int x = max(A[i][0], B[j][0]);
			int y;
			if (A[i][1] > B[j][1]) {
				y = B[j++][1];
			} else {
				y = A[i++][1];
			}
			if (x <= y)
				res.push_back({x, y});
		}
		return res;
	}
};