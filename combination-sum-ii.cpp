//Runtime: 9 ms
class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int>&temp, vector<int>&candidates, int target, int l)
    {
        if(target < 0)
            return;
        else if(!target)
            res.push_back(temp);
        else
        {
            for(int i=l;i<candidates.size();i++)
            {
                if(i > l && candidates[i] == candidates[i-1])   continue;
                temp.push_back(candidates[i]);
                solve(res, temp, candidates, target-candidates[i], i+1);
                temp.pop_back();
            }
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        solve(res, temp, candidates, target, 0);
        return res;
    }
};
