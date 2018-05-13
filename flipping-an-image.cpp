//Runtime: 15 ms
class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); i++) {
			int lo = 0, hi = A[i].size() - 1;

			while (lo <= hi) {
				int a = A[i][lo];
				int b = A[i][hi];

				A[i][hi--] = a ^ 1;
				A[i][lo++] = b ^ 1;
			}
		}
		return A;
	}
};