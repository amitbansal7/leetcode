//Runtime: 12 ms
class Solution {
public:

    void solve(vector<vector<int > >&res, vector<int> &temp, int l, int s,vector<int>&candidates, int target)
    {
        if(s == target)
            res.push_back(temp);

        if(s >= target)
            return;

        for(int i=l;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            solve(res, temp, i,s+candidates[i], candidates, target);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int > >res;
        vector<int> temp;

        solve(res, temp, 0, 0, candidates, target);

        return res;
    }
};
