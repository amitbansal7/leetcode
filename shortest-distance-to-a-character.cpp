//Runtime: 14 ms
class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> res(S.size(), INT_MAX);
		int prev = INT_MAX - 10004;

		for (int i = 0; i < S.size(); i++) {
			if (S[i] == C) prev = i;
			res[i] = min(res[i], abs(prev - i));
		}
		prev = INT_MAX - 10002;
		for (int i = S.size() - 1; i >= 0; i--) {
			if (S[i] == C) prev = i;
			res[i] = min(res[i], abs(prev - i));
		}
		return res;
	}
};