//Runtime: 6 ms
class Solution {
public:
    int ttl = 1;
    int f = 0;
    void solve(ListNode* head,int crnt,int n)
    {
        if(head->next == NULL)
            return;
        ttl++;

        solve(head->next, crnt+1, n);

        if(ttl-n == crnt && ttl!=n)
        {
            f = 1;
            head->next = head->next->next;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(n == 1 && head->next == NULL)
            return NULL;
        solve(head, 1, n);

        if(!f)
            return head->next;
        return head;
    }
};
