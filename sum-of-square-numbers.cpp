//Runtime: 6 ms
class Solution {
public:
    bool judgeSquareSum(int c) {
        int x = sqrt(c);
        for(int i=0;i<=x;i++)
            if(sqrt(c - i*i) == (int)sqrt(c - i*i))
                return 1;

        return 0;
    }
};
