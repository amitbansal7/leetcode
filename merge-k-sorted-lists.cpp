//Runtime: 25 ms
class Solution {
public:

    ListNode* Merge(ListNode* A, ListNode* B)
    {
        ListNode* result = new ListNode(-1);
        ListNode* tres = result;

        while(A && B)
        {
            if(A->val <= B->val)
            {
                result->next = A;
                result = result->next;
                A = A->next;
            }
            else
            {
                result->next = B;
                result = result->next;
                B = B->next;
            }
        }
        if(A)
            result->next = A;

        if(B)
            result->next = B;
        return tres->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        queue<ListNode*> Q;
        ListNode* res;
        for(ListNode* A:lists)
            Q.push(A);

        if(Q.size()== 1)
            return Q.front();

        while(Q.size()>1)
        {
            ListNode* A = Q.front();
            Q.pop();
            ListNode* B = Q.front();
            Q.pop();

            res = Merge(A,B);
            Q.push(res);
        }

        return res;
    }
};
