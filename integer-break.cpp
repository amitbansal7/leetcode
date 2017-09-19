//DP solution
//Runtime: 3 ms
class Solution {
public:
    int integerBreak(int n) {

        if(n == 2)
            return 1;

        vector<int>DP({0,1,2});

        for(int i=3;i<=n;i++)
        {
            int ans = -1;
            for(int j=1;j<=i;j++)
            {

                if(i-j== j)
                    ans =  max(ans,j * j);
                else
                    ans = max(ans,j * DP[i-j]);
            }

            DP.push_back(ans);
        }
        return DP[n];
    }
};


//Math solution
//Runtime: 0 ms
class Solution {
public:
    int integerBreak(int n) {

        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;

        int ans = 1;
        while(n>4)
        {
            n-=3;
            ans *= 3;
        }

        return ans*n;
    }
};
