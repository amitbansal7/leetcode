//Runtime: 9 ms
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int> > res;
        if(root == NULL)
            return res;
        queue<pair<int,TreeNode* > >Q;
        Q.push(make_pair(0,root));
        vector<int> lvl[1000];

        lvl[0].push_back(root->val);

        int maxlevel = 1;
        int f = 1;

        while(!Q.empty())
        {
            pair<int, TreeNode*> t = Q.front();
            Q.pop();


            if(t.second->left!=NULL)
            {
                Q.push(make_pair(t.first+1,t.second->left));
                lvl[t.first+1].push_back(t.second->left->val);
                maxlevel++;
                f = 0;
            }

            if(t.second->right!=NULL)
            {
                Q.push(make_pair(t.first+1,t.second->right));
                lvl[t.first+1].push_back(t.second->right->val);

                if(f)
                    maxlevel++;
                else
                    f = 1;
            }
        }

        for(int i=0;i<1000;i++)
            if(lvl[i].size() > 0)
                res.push_back(lvl[i]);

        return res;
    }
};


//Runtime: 3 ms
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int> > res;
        if(root == NULL)
            return res;
        queue<pair<int,TreeNode* > >Q;
        Q.push(make_pair(0,root));

        int maxlvl = 0;

        vector<int>ch;

        while(!Q.empty())
        {
            pair<int, TreeNode*> t = Q.front();
            Q.pop();

            if(maxlvl < t.first)
            {
                if(ch.size() > 0)
                {
                    res.push_back(ch);
                    ch.clear();
                }

                maxlvl++;
            }

            ch.push_back(t.second->val);

            if(t.second->left!=NULL)
                Q.push(make_pair(t.first+1,t.second->left));

            if(t.second->right!=NULL)
                Q.push(make_pair(t.first+1,t.second->right));
        }

        if(ch.size() > 0)
            res.push_back(ch);

        return res;
    }
};
