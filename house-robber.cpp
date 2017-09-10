//Runtime: 3 ms
class Solution {
public:

    int rob(vector<int>& nums) {
        int incl = 0;
        int excl = 0;

        for(auto i:nums)
        {
            int newecl = incl;
            incl = max(incl, excl+i);
            excl = newecl;
        }
        return max(incl, excl);

    }
};
