//Runtime: 5 ms
class Solution {
public:

	string goat(string t, int str) {
		if (t[0] == 'a' || t[0] == 'e' || t[0] == 'i' || t[0] == 'o' || t[0] == 'u' || t[0] == 'A' || t[0] == 'E' || t[0] == 'I' || t[0] == 'O' || t[0] == 'U') {
			t += "ma";
		} else {
			t += t[0];
			t += "ma";
			t.erase(0, 1);
		}

		for (int j = 0; j < str; j++) {
			t += "a";
		}
		return t;
	}

	string toGoatLatin(string S) {
		string res = "";
		string t = "";
		int str = 1;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == ' ') {

				res += " " + goat(t, str);
				str++;
				t.clear();
			} else {
				t += S[i];
			}
		}

		res += " " + goat(t, str);
		t.clear();
		res.erase(0, 1);
		return res;
	}
};