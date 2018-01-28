//Runtime: 9 ms
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int res = 0;
		for (char c : J) {
			for (char s : S) {
				if (c == s)
					res++;
			}
		}
		return res;
	}
};
