//Runtime: 29 ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> S;
        for(auto it:nums)
            S.insert(it);
        vector<int> q(S.begin(),S.end());
        nums = q;
        return S.size();
    }
};
