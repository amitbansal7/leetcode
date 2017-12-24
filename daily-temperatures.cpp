//Runtime: 229 ms
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res(temperatures.size());
        stack<int> S;

        for (int i = temperatures.size() - 1; i >= 0; i--) {

            while (!S.empty() && temperatures[S.top()] <= temperatures[i])
                S.pop();

            if (!S.empty())
                res[i] = S.top() - i;
            else
                res[i] = 0;;

            S.push(i);
        }

        return res;
    }
};
