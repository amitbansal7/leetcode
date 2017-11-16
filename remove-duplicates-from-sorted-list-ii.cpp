//Runtime: 9 ms
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode* prev = newHead;

        while(head)
        {
            int d = head->val;
            if(head->next && head->next->val == d)
            {
                while(head && head->val == d)
                    head = head->next;

                prev->next = head;
            }
            else
            {
                if(prev)
                    prev = prev->next;
                head = head->next;
            }

        }
        return newHead->next;
    }
};
