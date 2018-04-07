//Runtime: 67 ms
class Solution {
public:
	int look(char c, string &t, int idx) {
		for (int i = idx; i < t.size(); i++) {
			if (t[i] == c) {
				return i;
			}
		}
		return -1;
	}

	bool isSubsequence(string s, string t) {
		int idx = -1;
		for (char c : s) {
			idx = look(c, t, idx + 1);
			if (idx == -1) {
				return 0;
			}
		}
		return 1;
	}
};