//Runtime: 8 ms
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ten = 0, five = 0;

        for (int a : bills) {
            if (a == 5) {
                five++;
            } else if (a == 10) {
                five--;
                ten++;
            } else if (a == 20) {
                if (ten > 0) {
                    ten--; five--;
                }
                else
                    five -= 3;
            }

            if (five < 0) return false;
        }
        return true;
    }
};