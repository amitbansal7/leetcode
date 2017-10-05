//Runtime: 9 ms
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || head->next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && slow!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast!=NULL)
                fast = fast->next;
            if(!fast)
                return NULL;

            if(slow == fast)
                break;
        }
        slow = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
