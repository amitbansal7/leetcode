// Runtime: 220 ms
// Memory Usage: 24.5 MB
class Solution {
public:
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> res;

    while (head) {
      res.push_back(head->val);
      head = head->next;
    }
    stack<int> s;

    for (int i = res.size() - 1; i >= 0; i--) {
      int t = res[i];
      while (!s.empty() && s.top() <= res[i]) {
        s.pop();
      }

      res[i] = s.empty() ? 0 : s.top();

      s.push(t);

    }

    return res;
  }
};