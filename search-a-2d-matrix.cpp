//Runtime: 9 ms
class Solution {
public:

	bool binary(vector<vector<int> >&M, int r, int f)
	{
		int l = 0;
		int hi = M[0].size();

		while (l <= hi)
		{
			int mid = l + (hi - l) / 2;

			if (f == M[r][mid])
				return 1;
			else if (f > M[r][mid])
				l = mid + 1;
			else
				hi = mid - 1;
		}
		return 0;
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		if (rows < 1)
			return 0;
		int cols = matrix[0].size();
		if (cols < 1)
			return 0;

		int l = 0;

		int hi = rows - 1;
		while (l <= hi)
		{
			int midr = l + (hi - l) / 2;

			if (target >= matrix[midr][0] && target <= matrix[midr][cols - 1])
				return binary(matrix, midr, target);
			else if (target < matrix[midr][0])
				hi = midr - 1;
			else if (target > matrix[midr][cols - 1])
				l = midr + 1;
		}
		return 0;
	}
};
