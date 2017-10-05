//Runtime: 125 ms
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1] > 0)
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            else
                res.push_back(abs(nums[i]));
        }
        return res;
    }
};
