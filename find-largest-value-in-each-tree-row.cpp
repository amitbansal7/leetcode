//Runtime: 12 ms
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        vector<int>res;

        if(!root)
            return res;

        vector<int>temp;
        queue<pair<int, TreeNode*> >Q;
        Q.push(make_pair(0,root));

        int maxlvl = 0;

        while(!Q.empty())
        {
            pair<int,TreeNode*> t = Q.front();
            Q.pop();

            if(t.first > maxlvl)
            {
                 maxlvl++;
                if(temp.size() > 0)
                {
                    int maxa = INT_MIN;
                    for(int a:temp)
                        maxa = max(a, maxa);

                    temp.clear();
                    res.push_back(maxa);
                }

            }
            temp.push_back(t.second->val);
            if(t.second->left)
                Q.push(make_pair(t.first+1, t.second->left));

            if(t.second->right)
                Q.push(make_pair(t.first+1, t.second->right));
        }

        if(temp.size() > 0)
        {
            int maxa = INT_MIN;
            for(int a:temp)
                maxa = max(maxa, a);
            res.push_back(maxa);
        }

        return res;
    }
};
