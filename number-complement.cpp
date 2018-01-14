//Runtime: 8 ms
class Solution {
public:
	int findComplement(int num) {
		//mask is all right most bits set to 1
		int mask = num;

		mask |= mask >> 1;
		mask |= mask >> 2;
		mask |= mask >> 4;
		mask |= mask >> 8;
		mask |= mask >> 16;
		return num ^ mask;
	}
};
