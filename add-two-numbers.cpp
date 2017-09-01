class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        struct ListNode* result;
        struct ListNode* temp;
        int carry = 0;
        int f = 1;
        while(l1!=NULL || l2!=NULL)
        {
            int x = (l1!=NULL)?l1->val:0;
            int y = (l2!=NULL)?l2->val:0;

            int sum = x + y + carry;
            carry = sum/10;
            if(f)
            {
                result = new ListNode(sum%10);
                temp = result;
                f = 0;
            }
            else
            {
                result->next = new ListNode(sum%10);
                result = result->next;
            }

            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if(carry)
            result->next = new ListNode(carry);

        return temp;
    }
};
