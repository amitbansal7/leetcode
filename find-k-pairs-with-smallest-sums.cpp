//Runtime: 12 ms
class Solution {
public:

	void minHeapify(vector<pair<int, pair<int, int> > > &pairs, int i) {
		int l = i * 2 + 1;
		int r = i * 2 + 2;

		int smol = i;

		if (l < pairs.size() && pairs[l].first < pairs[smol].first) {
			smol = l;
		}

		if (r < pairs.size() && pairs[r].first < pairs[smol].first) {
			smol = r;
		}

		if (smol != i) {
			swap(pairs[i], pairs[smol]);
			minHeapify(pairs, smol);
		}
	}

	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

		vector<pair<int, pair<int, int> > > pairs;
		vector<pair<int, int> >res;

		if (nums1.size() == 0 || nums2.size() == 0) {
			return res;
		}

		for (int j = 0; j < nums2.size(); j++) {
			pairs.push_back(make_pair(nums1[0] + nums2[j], make_pair(0, j)));
		}

		int n = pairs.size();
		for (int i = n / 2 - 1; i >= 0; i--) {
			minHeapify(pairs, i);
		}


		for (int i = 0; i < k; i++) {
			if (i >= nums1.size()*nums2.size())
				return res;
			res.push_back(make_pair(nums1[pairs[0].second.first], nums2[pairs[0].second.second]));

			if (pairs[0].second.first != nums1.size() - 1) {
				pairs[0] = make_pair(
				               nums1[pairs[0].second.first + 1] + nums2[pairs[0].second.second],
				               make_pair(pairs[0].second.first + 1, pairs[0].second.second)
				           );
			} else {
				pairs[0] = make_pair(INT_MAX, make_pair(-1, -1));
			}
			minHeapify(pairs, 0);
		}

		return res;
	}
};