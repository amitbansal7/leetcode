//Runtime: 6 ms
class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		map<int, int> mp;
		for (int i = 0; i < B.size(); i++) {
			mp[B[i]] = i;
		}
		vector<int> res;
		for (int a : A) {
			res.push_back(mp[a]);
		}
		return res;
	}
};
