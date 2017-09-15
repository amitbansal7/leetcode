//Runtime: 3 ms
class Solution {
public:

    bool valid(char c) { return c!='0'; }
    bool valid(char a,char b) { return a == '1' || (a=='2' && b<='6'); }

    int solve(string s,int i,int DP[])
    {
        if(i<=1)
            return 1;

        if(DP[i] != -1)
            return DP[i];

        char f = s[i-1];
        char l = s[i-2];

        int a =0;
        if(valid(f))
            a = solve(s,i-1,DP);

        if(valid(l,f))
            a += solve(s,i-2,DP);

        return DP[i] = a;
    }
    int numDecodings(string s) {

        int l = s.size();
        if(l==0 || s[0] == '0')
            return 0;
        if(l==1)
            return l;


        int DP[l+1];
        for(int i=0;i<=l;i++)
            DP[i] = -1;

        return solve(s, l,DP);
    }
};
