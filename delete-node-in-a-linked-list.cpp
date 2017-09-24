//Runtime: 13 ms
class Solution {
public:
    void deleteNode(ListNode* node) {

        if(node->next->next==NULL)
        {
            node->val = node->next->val;
            node->next = NULL;
            return ;
        }

        while(node->next->next!=NULL)
        {
            node->val = node->next->val;
            node = node->next;
        }

        node->val = node->next->val;
        node->next = NULL;
    }
};

// Runtime: 13 ms(from "Submission Details")
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};
