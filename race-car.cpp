//Runtime: 761 ms
class Solution {
public:
	int racecar(int target) {
		if (target == 0)
			return 0;

		int res = 0;

		queue<pair<int, int> > q;
		set<pair<int, int> > s;
		q.push(make_pair(0, 1));
		s.insert(make_pair(0, 1));

		while (!q.empty()) {
			res++;
			queue<pair<int, int> >tq;

			while (!q.empty()) {
				pair<int, int> pr = q.front();
				q.pop();
				int p1 = pr.first + pr.second;
				int s1 = pr.second * 2;

				if (p1 == target)
					return res;

				int p2 = pr.first;
				int s2 = pr.second > 0 ? -1 : 1;

				tq.push(make_pair(p1, s1));
				if (s.find(make_pair(p2, s2)) == s.end()) {
					s.insert(make_pair(p2, s2));
					tq.push(make_pair(p2, s2));
				}
			}
			q = tq;
		}
		return -1;
	}
};