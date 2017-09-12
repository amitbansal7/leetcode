//My solution
//Runtime: 6 ms
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL)
            return head;

        if(!head->next)
            return head;

        if(head->next->next == NULL)
        {
            ListNode* t = head->next;
            head->next->next = head;
            head->next = NULL;
            return t;
        }
        ListNode* temp = NULL;
        ListNode *one, *two, *three;
    	while(head->next!=NULL)
        {
            one = head;
            two = head->next;
            three = two->next;
            two->next = one;
            one->next = temp;
            temp = two;
            head = three;
            if(head == NULL)
            {
                head = temp;
                return head;
            }
    	}
        head->next = temp;

    	return head;

    }
};


//Clean solution
//Runtime: 6 ms
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
