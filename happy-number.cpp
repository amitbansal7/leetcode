//Runtime: 3 ms
class Solution {
public:
    bool isHappy(int n) {
        set<int>S;
        S.insert(n);
        while(1)
        {
            int s = 0;
            while(n > 0)
            {
                int r = n%10;
                s += r*r;
                n /= 10;
            }
            if(s==1)
                return 1;
            int l = S.size();
            S.insert(s);
            if(l == S.size())
                return 0;
            n = s;
        }
    }
};
