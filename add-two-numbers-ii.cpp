//Runtime: 42 ms
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>a;
        stack<int>b;

        while (l1)
        {
            a.push(l1->val);
            l1 = l1->next;
        }

        while (l2)
        {
            b.push(l2->val);
            l2 = l2->next;
        }

        int r = 0;
        ListNode* res = new ListNode(-1);
        ListNode* t = res;
        while (!a.empty() || !b.empty())
        {
            int n = r;
            if (!a.empty())
            {
                n += a.top();
                a.pop();
            }

            if (!b.empty())
            {
                n += b.top();
                b.pop();
            }
            r = n / 10;
            n = n % 10;
            res->next = new ListNode(n);
            res = res->next;
        }
        if (r > 0)
            res->next = new ListNode(r);
        res = t->next;
        ListNode* prev = NULL;
        ListNode* next;
        while (res)
        {
            next = res->next;
            res->next = prev;
            prev = res;
            res = next;
        }
        return prev;
    }
};
