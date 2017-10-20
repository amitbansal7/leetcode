//Runtime: 35 ms
class Solution {
public:
    int arrangeCoins(int n) {
        return floor(-0.5 + sqrt((double)2*n+0.25));
    }
};
