//Runtime: 16 ms
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* last = new ListNode(-1);
        ListNode* tlast = last;
        ListNode* crawl = head;
        ListNode* tcrawl = NULL;

        for(int i=0;crawl;i++)
        {
            if(i%2==0)
            {
                ListNode* t = crawl->next;
                if(crawl->next)
                    crawl->next = crawl->next->next;
                last->next = t;
                last = last->next;
                tcrawl = crawl;
                crawl = crawl->next;
            }
        }
        tcrawl->next = tlast->next;
        return head;
    }
};
