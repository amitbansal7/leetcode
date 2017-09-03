//Runtime: 9 ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* res = new ListNode(0);
        ListNode* ans = res;

        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                res->next = l1;
                l1 = l1->next;
            }
            else
            {
                res->next = l2;
                l2 = l2->next;
            }

            res = res->next;
        }
        res->next = l1?l1:l2;

        return ans->next;
    }
};
