//Runtime: 12 ms
class Solution {
public:
	string addStrings(string num1, string num2) {
		int i = num1.size() - 1;
		int j = num2.size() - 1;
		int carry = 0;
		string res;
		while (i >= 0 || j >= 0) {
			int x = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;
			carry = x / 10;
			res += (x % 10 + '0');
			i--; j--;
		}

		if (carry != 0) {
			res += (carry + '0');
		}

		reverse(res.begin(), res.end());
		return res;
	}
};