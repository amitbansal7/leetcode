//Runtime: 12 ms
class Solution {
public:

    void solve(vector<int> &temp, bool used[], vector<int>&nums,int depth, vector<vector<int> > &res)
    {
        if(depth == nums.size())
        {
            res.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(!used[i])
            {
                temp.push_back(nums[i]);
                used[i] = 1;
                solve(temp, used, nums, depth+1, res);
                used[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int> > res;
        if(nums.size()<1)
            return res;

        vector<int> temp;
        bool used[nums.size()];
        for(int i=0;i<nums.size();i++)
            used[i] = 0;

        solve(temp, used, nums, 0, res);
        return res;
    }
};
