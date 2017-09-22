//Runtime: 9 ms
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(!head || !head->next)
            return 0;

        ListNode *slow, *fast;
        slow = fast = head;
        fast = fast->next;
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast->next!=NULL)
                fast = fast->next;

            if(fast == slow)
                return 1;
        }

        return 0;
    }
};
