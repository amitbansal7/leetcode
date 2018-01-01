//Runtime: 3 ms
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 0)
			return n;
		return ceil(log2(n)) == floor(log2(n));
	}
};
