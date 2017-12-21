//Runtime: 3 ms
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;

        for (int i = 0; input[i]; i++) {
            char op = input[i];
            if (op == '+' || op == '-' || op == '*') {
                vector<int> t1 = diffWaysToCompute(input.substr(0, i));
                vector<int> t2 = diffWaysToCompute(input.substr(i + 1));

                for (int a : t1) {
                    for (int b : t2) {
                        if (op == '+') {
                            res.push_back(a + b);
                        } else if (op == '-') {
                            res.push_back(a - b);
                        } else {
                            res.push_back(a * b);
                        }
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(atoi(input.c_str()));
        }
        return res;
    }
};
