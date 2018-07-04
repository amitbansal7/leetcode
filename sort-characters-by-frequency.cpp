//Runtime: 18 ms
class Solution {
public:
	string frequencySort(string s) {
		map<char, int> mp;

		for (char c : s) {
			mp[c]++;
		}

		vector<pair<char, int> >vec(mp.begin(), mp.end());

		sort(vec.begin(), vec.end(), [](auto & l, auto & r) {
			return l.second > r.second;
		});

		string res = "";

		for (pair<char, int> p : vec) {
			for (int i = 0; i < p.second; i++) {
				res += p.first;
			}
		}
		return res;
	}
};