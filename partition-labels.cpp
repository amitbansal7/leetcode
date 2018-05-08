//Runtime: 8 ms
class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> lastChar(26, 0);
		for (int i = 0; i < S.size(); i++) {
			lastChar[S[i] - 'a'] = i;
		}
		int part = 0;
		int j = 0;
		vector<int> res;
		for (int i = 0; i < S.size(); i++) {
			j = max(j, lastChar[S[i] - 'a']);
			if (i == j) {
				res.push_back(i - part + 1);
				part = i + 1;
			}
		}
		return res;
	}
};