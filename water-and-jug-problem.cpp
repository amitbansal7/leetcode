//Runtime: 0 ms
class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (x + y < z)
			return 0;

		if (x == z || y == z || x + y == z)
			return 1;
		if (x == 0 || y == 0) {
			if (x == z || y == z)
				return 1;
			else
				return 0;
		}

		while (x != y) {
			if (x > y)
				x = x - y;
			else
				y = y - x;
		}

		return z % x == 0;
	}
};
