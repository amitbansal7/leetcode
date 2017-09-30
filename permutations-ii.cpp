//Runtime: 23 ms
class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int> &temp,vector<int> Unums, vector<int> Count, int depth,int l)
    {
        if(depth == l)
        {
            res.push_back(temp);
            return;
        }

        for(int i=0;i<Unums.size();i++)
        {
            if(Count[i])
            {
                temp.push_back(Unums[i]);
                Count[i]--;
                solve(res, temp, Unums, Count, depth+1, l);
                Count[i]++;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int> > res;
        vector<int> temp;
        if(nums.size() < 1)
        {
            res.push_back(temp);
            return res;
        }

        map<char, int> Map;
        map<char, int> :: iterator it;
        for(auto a:nums)
            Map[a]++;

        vector<int> Unums;
        vector<int> Count;

        for(it = Map.begin();it!=Map.end();it++)
        {
            Unums.push_back(it->first);
            Count.push_back(it->second);
        }

        solve(res, temp, Unums, Count, 0, nums.size());

        return res;
    }
};
