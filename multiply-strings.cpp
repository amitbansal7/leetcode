//Runtime: 9 ms
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.size() == 0 || num2.size() == 0)
			return "0";
		vector<int>resv(num1.size() + num2.size(), 0);
		int a = 0, b = 0;
		for (int i = num1.size() - 1; i >= 0; i--) {
			int carry = 0;
			b = 0;
			int n1 = num1[i] - '0';
			for (int j = num2.size() - 1; j >= 0; j--) {
				int n2 = num2[j] - '0';
				int sum = n1 * n2 + carry + resv[a + b];
				resv[a + b] = sum % 10;
				carry = sum / 10;
				b++;
			}
			if (carry > 0)
				resv[a + b] += carry;

			a++;
		}

		int i = resv.size() - 1;
		while (i >= 0 && resv[i] == 0)
			i--;

		if (i == -1)
			return "0";
		string res = "";
		while (i >= 0)
			res += to_string(resv[i--]);
		return res;
	}
};
