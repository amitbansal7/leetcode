//Runtime: 3 ms
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if(!head)
            return head;

        if(!head->next)
            return head;

    	ListNode* nhead = new ListNode(0);
    	nhead->next = head;

    	ListNode* M = nhead;

    	for(int i=0;i<m-1;i++)
    		M = M->next;

        ListNode* two = M;
        M = M->next;
        ListNode* tm = M;
        ListNode* prev = NULL;
        ListNode* next;
        for(int i=0;i<=n-m;i++)
        {
            next = M->next;
            M->next = prev;
            prev = M;
            M = next;

        }
        tm->next = M;
        two->next = prev;
        return nhead->next;
    }
};
