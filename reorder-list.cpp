//Runtime: 49 ms
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        while (fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;

            if (fast)
                fast = fast->next;
        }
        prev->next = NULL;

        ListNode* next;
        ListNode* pr = NULL;

        while (slow)
        {
            next = slow->next;
            slow->next = pr;
            pr = slow;
            slow = next;
        }

        while (head && pr)
        {
            ListNode* nextHead = head->next;
            head->next = pr;
            ListNode* newpr = pr->next;
            pr->next = nextHead;
            head = nextHead;
            pr = newpr;
        }
    }
};
