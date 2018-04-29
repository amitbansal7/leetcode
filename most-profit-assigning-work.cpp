//Runtime: 97 ms
class Solution {
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		vector<pair<int, int> > jobs;
		int n = profit.size();
		for (int i = 0; i < n; i++) {
			jobs.push_back(make_pair(difficulty[i], profit[i]));
		}

		sort(jobs.begin(), jobs.end());
		sort(worker.begin(), worker.end());

		int res = 0;
		int s = 0, best = 0;
		for (int sk : worker) {
			while (s < n && sk >= jobs[s].first) {
				best = max(best, jobs[s++].second);
			}
			res += best;
		}
		return res;
	}
};