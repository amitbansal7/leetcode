//Runtime: 7 ms
class Solution {
public:
	int hammingDistance(int x, int y) {
		int res = 0;
		for (int i = 0; i < 32; i++) {
			if ((x & (1 << i)) != (y & (1 << i)))
				res++;
		}
		return res;
	}
};

//Runtime: 7 ms
class Solution {
public:
	int hammingDistance(int x, int y) {
		int res = 0;
		x = x ^ y;

		while (x) {
			res++;
			x = x & (x - 1);
		}
		return res;
	}
};
