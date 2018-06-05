//Runtime: 5 ms
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> one;
        stack<char> two;

        for (char c : S) {
            if (c != '#')    one.push(c);
            else {
                if (!one.empty()) one.pop();
            }
        }

        for (char c : T) {
            if (c != '#')    two.push(c);
            else {
                if (!two.empty()) two.pop();
            }
        }

        while (!one.empty() || !two.empty()) {

            if (one.empty()) return false;
            if (two.empty()) return false;

            if (one.top() != two.top()) {
                return false;
            }
            one.pop(); two.pop();
        }
        return true;
    }
};