//Runtime: 6 ms
class Solution {
public:

    void solve(vector<vector<int> >&res, vector<int>&temp, vector<int>&nums, int l)
    {
        res.push_back(temp);
        if(l>=nums.size())
            return;

        for(int i=l;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            solve(res, temp, nums, i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int>temp;
        solve(res, temp, nums, 0);
        return res;
    }
};
