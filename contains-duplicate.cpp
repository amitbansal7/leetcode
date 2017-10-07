//Runtime: 26 ms
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;

        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++)
            if(nums[i] == nums[i-1])
                return 1;

        return 0;
    }
};
