//Runtime: 109 ms
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> M;
        map<int,int> :: iterator vit;
        int ans = 0;

        for(auto a:nums)
            M[a]++;

        for(pair<int,int> p :M)
        {
            vit = M.find(p.first +1);

            if(vit!=M.end())
                ans = max(ans, vit->second+p.second);
        }

        return ans;
    }
};
