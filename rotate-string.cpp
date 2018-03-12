//Runtime: 4 ms
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size())
            return 0;

        int sz = A.size();
        map<char, vector<int> > mp;

        for (int i = 0; i < sz; i++) {
            mp[A[i]].push_back(i);
        }

        for (int i = 0; i < sz; i++) {
            if (mp.find(B[i]) == mp.end())
                return 0;
            int ans = 0;

            for (int a : mp[B[i]]) {
                ans = ans || (B[(i + 1) % sz] == A[(a + 1) % sz]);
            }

            if (ans == 0)
                return 0;

        }
        return 1;
    }
};