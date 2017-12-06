//Runtime: 9 ms
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        ListNode* t = root;
        while (t) {
            n++;
            t = t->next;
        }
        vector<ListNode* >res;
        int nodep = n / k;
        int rem = n % k;

        for (int i = 0; i < k; i++) {
            ListNode* head = new ListNode(0);
            ListNode* thead = head;

            for (int j = 0; j < nodep + (i < rem) ? 1 : 0; j++) {
                head->next = new ListNode(root->val);
                head = head->next;
                if (root)
                    root = root->next;
            }
            res.push_back(thead->next);
        }
        return res;
    }
};
