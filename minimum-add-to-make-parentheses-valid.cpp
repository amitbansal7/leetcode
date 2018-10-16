//Runtime: 0 ms
class Solution {
public:
    int minAddToMakeValid(string S) {
        int close = 0;
        int open = 0;
        for (char c : S) {
            if (c == '(') {
                open++;
            } else if (c == ')') {
                if (open > 0)    open--;
                else    close++;
            }
        }

        return (close + open);
    }
};