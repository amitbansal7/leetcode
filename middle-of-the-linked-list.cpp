//Runtime: 0 ms
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        return slow;
    }
};