//My solution
//Runtime: 885 ms
class Solution {
public:
    bool ans = 0;

    void solve(vector<int>&nums, vector<bool>&look, int sum, int ttl, set<int>&S)
    {
        if(sum == ttl-sum)
        {
            ans = 1;
            return;
        }
        int a = 0;
        int ls = S.size();
        S.insert(sum);
        if(ls == S.size())
            return ;
        for(int i=0;i<nums.size();i++)
        {
            if(!look[i])
            {
                look[i] = 1;
                if(!ans)
                    solve(nums, look, sum+nums[i], ttl,S);
                look[i] = 0;
            }
        }
    }

    bool canPartition(vector<int>& nums) {
        vector<bool>look(nums.size(), 0);
        int ttl = 0;

        for(int i=0;i<nums.size();i++)
            ttl += nums[i];

        set<int>S;
        solve(nums, look, 0, ttl,S);
        return ans;
    }
};

//Runtime: 63 ms
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int a:nums)
            sum += a;

        if(sum & 1)
            return 0;
        sum /= 2;
        vector<bool>DP(sum+1, 0);
        DP[0] = 1;

        for(int a:nums)
            for(int i=sum;i>=0;i--)
                if(i>=a)
                    DP[i] = DP[i] || DP[i-a];

        return DP[sum];
    }
};
