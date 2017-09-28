//My solution
//Runtime: 26 ms
class Solution {
public:
    void solve(TreeLinkNode* root,stack<TreeLinkNode*>S)
    {
        if(!root)
            return;

        else if(S.empty())
            root->next = NULL;

        else if(S.top()->left == root)
            root->next = S.top()->right;

        else
        {
            TreeLinkNode* tparent = S.top();
            stack<TreeLinkNode*> tS;
            tS.push(S.top());
            S.pop();
            int lvl = 1;

            while(!S.empty() && S.top()->right == tparent)
            {
                tparent = S.top();
                tS.push(tparent);
                S.pop();
                lvl++;
            }
            int mhe = 0;
            TreeLinkNode* mainhead;
            if(!S.empty())
            {
                mainhead = S.top()->right;
                mhe = 1;
            }
            else
                mainhead = NULL;

            while(mhe && lvl--)
                mainhead = mainhead->left;

            root->next = mainhead;

            while(!tS.empty())
            {
                S.push(tS.top());
                tS.pop();
            }
        }

        S.push(root);
        solve(root->left, S);
        solve(root->right, S);
    }
    void connect(TreeLinkNode *root) {
    	stack<TreeLinkNode*> S;
        solve(root, S);
    }
};

//Simpler solution (learned from discuss section)
//Runtime: 26 ms
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        TreeLinkNode* prev = root;
        TreeLinkNode* cur = NULL;

        while(prev->left)
        {
            cur = prev;
            while(cur)
            {
                cur->left->next = cur->right;
                if(cur->next)
                    cur->right->next = cur->next->left;

                cur = cur->next;
            }
            prev = prev->left;
        }
    }
};
