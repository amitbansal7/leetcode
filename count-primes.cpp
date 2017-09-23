//Runtime: 289 ms
class Solution {
public:

    bool isprime(int n)
    {
        if(n<=1) return 0;

        if(n<=3) return 1;

        if(n%2==0 || n%3==0) return 0;

        int  i =5;

        while(i*i<=n)
        {
            if(n%i==0 || n%(i+2) == 0)
                return 0;

            i+=6;
        }
        return 1;
    }

    int countPrimes(int n) {
        int cnt = 0;

        for(int i=0;i<n;i++)
            if(isprime(i))
                cnt++;

        return cnt;
    }
};

//Runtime: 16 ms
//sieve of eratosthenes
class Solution {
public:

    int countPrimes(int n) {
        int cnt = 0;

        if(n<=2)
            return 0;

        bool S[n+1];
        memset(S, true, sizeof(S));

        for(int i=2;i<sqrt(n);i++)
            if(S[i])
                for(int j=i*i;j<=n;j+=i)
                    S[j] = 0;

        for(int i=2;i<n;i++)
            if(S[i])
                cnt++;

        return cnt;
    }
};
