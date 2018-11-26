//Runtime: 12 ms
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() != popped.size())
			return false;

		stack<int> s;
		int i = 0;
		for (int a : pushed) {
			s.push(a);
			while (!s.empty() && i < popped.size()) {
				if (s.top() == popped[i]) {
					s.pop();
					i++;
				} else break;
			}
		}

		return s.size() == 0;
	}
};