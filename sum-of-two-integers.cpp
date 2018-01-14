//Runtime: 2 ms
class Solution {
public:
	int getSum(int a, int b) {
		int t;
		while (b) {
			t = a ^ b;
			b = (a & b) << 1;
			a = t;
		}
		return a;
	}
};
