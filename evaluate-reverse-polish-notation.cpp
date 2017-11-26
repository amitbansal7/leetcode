//Runtime: 9 ms
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;

        for (string s : tokens)
        {
            if (s == "+")
            {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                S.push(a + b);
            }
            else if (s == "-")
            {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                S.push(b - a);
            }
            else if (s == "*")
            {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                S.push(a * b);
            }
            else if (s == "/")
            {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                S.push(b / a);
            }
            else
                S.push(stoi(s));
        }
        return S.top();
    }
};
