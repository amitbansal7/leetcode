//Runtime: 26 ms
//Learned from discuss section
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* head = NULL;
        TreeLinkNode* prev = NULL;
        TreeLinkNode* cur = root;

        while(cur)
        {
            while (cur)
            {
                if (cur->left)
                {
                    if (prev)
                        prev->next = cur->left;
                    else
                        head = cur->left;

                    prev = cur->left;
                }

                if (cur->right)
                {
                    if (prev)
                        prev->next = cur->right;
                    else
                        head = cur->right;
                    prev = cur->right;
                }

                cur = cur->next;
            }
            cur = head;
            head = NULL;
            prev = NULL;
        }

    }
};
