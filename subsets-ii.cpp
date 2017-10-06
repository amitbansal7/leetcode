//Runtime: 9 ms
class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int>temp, vector<int>&nums, int l)
    {
        res.push_back(temp);

        if(l >= nums.size())
            return;

        for(int i=l;i<nums.size();i++)
        {
            if(i > l && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            solve(res, temp, nums, i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        vector<int>temp;
        solve(res, temp, nums, 0);
        return res;

    }
};
