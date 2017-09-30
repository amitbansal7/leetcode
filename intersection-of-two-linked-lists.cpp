//Runtime: 36 ms
//Learned from solution section.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *p1,*p2;
        p1 = headA;
        p2 = headB;

        while(p1!=p2)
        {
            p1 = p1?p1->next:headB;
            p2 = p2?p2->next:headA;
        }
        return p1;
    }
};
