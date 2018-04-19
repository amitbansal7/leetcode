//Runtime: 46 ms
class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		map<int, int> mp;
		int size = 0;
		int minn = INT_MAX;
		int maxn = INT_MIN;
		for (auto vec : wall) {
			int c = 0;
			for (int i : vec) {
				c += i;
				mp[c]++;
				minn = min(minn, i);
				maxn = max(maxn, i);
			}
			size = c;
		}
		int res = INT_MAX;
		mp[size] = -INT_MIN;
		int ht = wall.size();

		for (auto &m : mp) {
			if (m.first != size)
				res = min(res, ht - m.second);
		}
		if (maxn == minn && res == INT_MAX)
			return ht;
		return res;
	}
};