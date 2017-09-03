//Runtime: 3 ms
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next)
            return head;

        ListNode* ans = new ListNode(0);
        ans->next = head;

        ListNode* slow = ans;
        ListNode* fast = ans->next->next;
        ListNode *one, *two, *three;
        while(fast!=NULL)
        {
            one = slow->next;
            two = fast;
            three = fast->next;

            slow->next = two;
            one->next = three;
            two->next = one;
            slow = two;
            fast = one;
            if(fast->next!=NULL && fast->next->next!=NULL)
                fast = fast->next->next;
            else
                break;
            slow = slow->next;
        }

        return ans->next;
    }
};
