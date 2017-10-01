//Runtime: 0 ms
class Solution {
public:
    int numTrees(int n) {
        int DP[n+1];
        DP[0] = 1;
        DP[1] = 1;

        for(int i=2;i<=n;i++)
        {
            DP[i] = 0;
            for(int j=0;j<i;j++)
                DP[i] += DP[j]*DP[i-j-1];
        }

        return DP[n];
    }
};
