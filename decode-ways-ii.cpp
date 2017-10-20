//Runtime: 62 ms
class Solution {
public:

    bool valid(char a, char b)  {   return a=='1' || (a=='2' && b<='6');  }

    int numDecodings(string s) {
        int MOD = 1000000007;
        int n = s.size();
        long long int DP[n+1];
        DP[0] = 1;
        DP[1] = s[0] == '*'?9:s[0] == '0'?0:1;

        for(int i=2;i<=n;i++)
        {
            if(s[i-1] == '*')
            {
                DP[i] = DP[i-1]*9;
                if(s[i-2] == '1')
                    DP[i] = (DP[i] + 9*DP[i-2])%MOD;
                else if(s[i-2] == '2')
                    DP[i] = (DP[i] + 6* DP[i-2])%MOD;
                else if(s[i-2] == '*')
                    DP[i] = (DP[i] + 15*DP[i-2])%MOD;
            }
            else
            {
                DP[i] = s[i-1] != '0'?DP[i-1]:0;

                if(valid(s[i-2],s[i-1]))
                    DP[i] = (DP[i] + DP[i-2]) % MOD;
                else if(s[i-2] == '*')
                    DP[i] = (DP[i] + (s[i-1] <='6' ? 2 : 1) * DP[i-2])%MOD;

            }
        }
        return (int)DP[n];
    }
};
