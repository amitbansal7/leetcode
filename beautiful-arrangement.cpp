//Runtime: 116 ms
//Backtracking
class Solution {
public:
    int ans = 0;
    void solve(bool ref[], int k, int n)
    {
        if(k > n)
        {
            ans++;
            return;
        }

        for(int i=1;i<=n;i++)
        {
            if(!ref[i] && (i%k==0 || k%i == 0))
            {
                ref[i] = 1;
                solve(ref, k+1, n);
                ref[i] = 0;
            }
        }
    }

    int countArrangement(int N) {

        bool ref[N+1];
        for(int i=1;i<=N;i++)
            ref[i] = 0;

        solve(ref, 1,N);
        return ans;
    }
};
