//Runtime: 114 ms
class Solution {
public:

	int findGlobal(vector<int> &A) {
		if (A.size() <= 1)
			return 0;

		int mid = A.size() / 2;
		vector<int>B(mid), C(A.size() - mid);
		for (int i = 0; i < mid; i++)
			B[i] = A[i];

		for (int i = mid; i < A.size(); i++)
			C[i - mid] = A[i];

		int x = findGlobal(B);
		int y = findGlobal(C);
		int z = 0;
		int l = 0, k = 0, i = 0;

		while (l < mid && k < A.size() - mid) {
			if (B[l] <= C[k]) {
				A[i++] = B[l++];
			} else {
				A[i++] = C[k++];
				z += (mid - l);
			}
		}

		while (l < mid) {
			A[i++] = B[l++];
		}

		while (k < A.size() - mid) {
			A[i++] = C[k++];
		}

		return x + y + z;
	}

	bool isIdealPermutation(vector<int>& A) {
		int loc = 0;
		for (int i = 0; i < A.size() - 1; i++) {
			if (A[i] > A[i + 1])
				loc++;
		}
		int glob = findGlobal(A);
		return loc == glob;
	}
};
