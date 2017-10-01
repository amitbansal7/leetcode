//Runtime: 223 ms
class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int> temp, vector<int>&nums, int k)
    {
        if(temp.size() >= 2)
            res.push_back(temp);

        unordered_set<int> S;
        for(int i=k;i<nums.size();i++)
        {
            if((temp.size() < 1 || temp.back() <= nums[i]) && S.find(nums[i]) == S.end())
            {
                temp.push_back(nums[i]);
                solve(res, temp, nums, i+1);
                temp.pop_back();
                S.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> temp;
        solve(res, temp, nums, 0);
        return res;
    }
};
