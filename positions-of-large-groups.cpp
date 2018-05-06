//Runtime: 20 ms
class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> res;

		for (int i = 0; i < S.size(); i++) {
			char ch = S[i];
			int s = i;
			while (S[i] == ch) {
				i++;
			}
			if (i - s >= 3) {
				vector<int> t;
				t.push_back(s);
				t.push_back(i - 1);
				res.push_back(t);
			}
			if (s != i)    i--;
		}
		return res;
	}
};