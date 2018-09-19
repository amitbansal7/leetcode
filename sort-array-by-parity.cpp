//Runtime: 44 ms
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> odd;
        vector<int> even;
        for (int a : A) {
            if (a % 2 == 0) {
                even.push_back(a);
            } else {
                odd.push_back(a);
            }
        }

        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};