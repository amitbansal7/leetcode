//Runtime: 19 ms
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)
            return 1;

        ListNode *slow,*fast;
        slow = fast = head;

        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast->next)
                fast = fast->next;
        }

        ListNode* prev = NULL;
        ListNode* cur = slow;
        ListNode* next = NULL;

        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        while(head!=NULL && prev!=NULL)
        {
            if(head->val!=prev->val)
                return 0;

            head = head->next;
            prev = prev->next;
        }
        return 1;
    }
};
