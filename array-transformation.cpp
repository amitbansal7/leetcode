// Runtime: 8 ms
// Memory Usage: 8.6 MB
class Solution {
public:
	vector<int> transformArray(vector<int>& arr) {
		while (1) {
			vector<int> t = arr;
			bool changed = false;
			for (int i = 1; i < arr.size() - 1; i++) {
				if (t[i] < t[i + 1] && t[i] < t[i - 1]) {
					arr[i]++;
					changed = true;
				} else if (t[i] > t[i + 1] && t[i] > t[i - 1]) {
					arr[i]--;
					changed = true;
				}
			}
			if (!changed) return arr;
		}
		return arr;
	}
};