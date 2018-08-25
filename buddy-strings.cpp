//Runtime: 4 ms
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A == B && set<char>(A.begin(), A.end()).size() != A.size()) return true;
        char da1, da2, db1, db2;
        int c = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                c++;
                if (c == 1) {
                    da1 = A[i];
                    db1 = B[i];
                } else if (c == 2) {
                    da2 = A[i];
                    db2 = B[i];
                } else return false;
            }
        }
        if (c != 2) return false;
        return da2 == db1 && da1 == db2;
    }
};