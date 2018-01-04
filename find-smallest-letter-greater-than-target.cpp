//Runtime: 16 ms
class Solution {
public:
	int ans = -1;

	void binary(vector<char>&l, int lo, int hi, char target) {
		if (lo > hi)
			return;

		int mid = lo + (hi - lo) / 2;
		bool a = 0;
		bool b = 0;
		if (target == l[mid]) {
			ans = mid;
			return;
		}

		if ((mid - 1 < 0 || (mid - 1 >= 0 && l[mid - 1] < target)) &&
		        (mid + 1 > hi || (mid + 1 <= hi && l[mid + 1] > target))) {

			ans = mid + 1;
			if (target < l[mid])
				ans = mid;
			return;
		}

		if (l[mid]  > target)
			binary(l, lo, mid - 1, target);
		else
			binary(l, mid + 1, hi, target);
	}

	char nextGreatestLetter(vector<char>& letters, char target) {
		int sz = letters.size();
		if (letters[sz - 1] <= target || target < letters[0])
			ans = 0;
		else if (target == letters[0])
			ans = 1;
		else
			binary(letters, 0, sz - 1, target);

		if (letters[ans] == target) {
			while (ans < sz && letters[ans] == letters[ans + 1])
				ans++;

			if (ans + 1 < sz)
				ans++;
		}
		return letters[ans];
	}
};
