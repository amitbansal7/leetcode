//Runtime: 6 ms
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* leftlist = new ListNode(-1);
        ListNode* ans = leftlist;
        ListNode* prev = head;
        ListNode* thead = new ListNode(INT_MAX);
        thead->next = head;
        head = thead;

        while(head)
        {
            if(head->val < x)
            {
                leftlist->next = head;
                leftlist = leftlist->next;
                prev->next = head->next;
                head = prev->next;
            }
            else
            {
                prev = head;
                head = head->next;
            }
        }

        leftlist->next = thead->next;
        return ans->next;
    }
};
