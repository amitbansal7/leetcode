//Runtime: 0 ms
class Solution {
public:
    int s = 0;
    int solve(int i,int DP[])
    {
        if(i<=1)
            return 0;

        if(DP[i] != -1)
            return DP[i];

        return DP[i] = 1 + solve(i-1,DP) + solve(i-2,DP);
    }
    int climbStairs(int n) {

        int DP[n+1];
        for(int i=0;i<=n;i++)
            DP[i] = -1;


        return solve(n, DP)+1;
    }
};
