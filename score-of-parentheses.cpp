//Runtime: 4 ms
class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0;
        int l = 0;

        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') l++;
            else l--;

            if (S[i] == '(' && S[i + 1] == ')')
                res += pow(2, l - 1);
        }
        return res;
    }
};