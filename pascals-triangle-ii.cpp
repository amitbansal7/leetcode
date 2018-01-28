//Runtime: 2 ms
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> temp;

		for (int i = 0; i <= rowIndex; i++) {
			vector<int>row(i + 1);
			row[0] = row[row.size() - 1] = 1;

			for (int j = 1; j < i; j++) {
				row[j] = temp[j - 1] + temp[j];
			}
			temp = row;
		}
		return temp;
	}
};
