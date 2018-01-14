//Runtime: 15 ms
class Solution {
public:

    bool isPrime(int n) {
        if (n <= 1)
            return 0;
        else if (n <= 3)
            return 1;
        else if (n % 2 == 0 || n % 3 == 0)
            return 0;

        int i = 5;
        while (i * i <= n) {
            if (n % i == 0  || n % (i + 2) == 0)
                return 0;
            i += 6;
        }
        return 1;
    }

    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int x = L; x <= R; x++) {
            int t = x;
            int c = 0;
            while (t) {
                t = t & (t - 1);
                c++;
            }

            if (isPrime(c)) {
                ans++;
            }
        }
        return ans;
    }
};
