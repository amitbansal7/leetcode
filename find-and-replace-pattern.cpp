//Runtime: 0 ms
class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> res;

		for (string w : words) {
			if (pattern.size() != w.size()) continue;
			map<char, char> mp;
			map<char, char> mp2;
			bool f = 1;
			for (int i = 0; i < pattern.size(); i++) {
				if (mp.find(pattern[i]) == mp.end()) {
					if (mp2.find(w[i]) != mp2.end()) {
						f = 0;
						break;
					}
					mp[pattern[i]] = w[i];
					mp2[w[i]] = pattern[i];
				}
				if (mp[pattern[i]] != w[i] || mp2[w[i]] != pattern[i]) {
					f = 0;
					break;
				}
			}
			if (f) res.push_back(w);
		}
		return res;
	}
};