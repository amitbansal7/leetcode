//Runtime: 3 ms
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<int, TreeNode* > >Q;
        Q.push(make_pair(1, root));
        vector<int>res;
        if(!root)
            return res;
        int maxlvl = 1;
        int prev = root->val;
        while(!Q.empty())
        {
            pair<int,TreeNode*> t = Q.front();
            Q.pop();

            if(t.first > maxlvl)
            {
                res.push_back(prev);
                maxlvl++;
            }
            prev = t.second->val;
            if(t.second->left)
                Q.push(make_pair(t.first+1, t.second->left));

            if(t.second->right)
                Q.push(make_pair(t.first+1, t.second->right));
        }

        res.push_back(prev);

        return res;
    }

};
