//Runtime: 13 ms
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = head;

        while(ans!=NULL)
        {
            if(ans->next!=NULL && ans->val == ans->next->val)
                ans->next = ans->next->next;
            else
                ans = ans->next;
        }

        return head;
    }
};
