//Runtime: 0 ms
class Solution {
public:
	int countSegments(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
				ans++;
		}
		return ans;
	}
};
