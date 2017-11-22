//Runtime: 55 ms
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int i, j;

		i = 0;
		if (matrix.size() < 1 || matrix[0].size() < 1)
			return 0;

		j = matrix[0].size() - 1;
		while (i < matrix.size() && j >= 0)
		{
			if (target == matrix[i][j])
				return 1;

			else if (target < matrix[i][j])
				j--;
			else
				i++;
		}
		return 0;
	}
};
