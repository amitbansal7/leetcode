//Runtime: 29 ms
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode * res = start;
        while(start->next!=NULL)
        {
            while(start->next!=NULL && start->next->val == val)
                start->next = start->next->next;

            if(start->next!=NULL)
                start = start->next;
        }
        return res->next;


    }
};
