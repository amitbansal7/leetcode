//Runtime: 3 ms
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int> > res;
        if(!root) return res;

        queue<pair<int, TreeNode* > >Q;
        Q.push(make_pair(0, root));

        vector<int> tmp;
        int maxlvl = 0;
        while(!Q.empty())
        {
            pair<int, TreeNode*> t = Q.front();
            Q.pop();

            if(t.first > maxlvl)
            {
                maxlvl++;
                if(tmp.size() > 0)
                {
                    if(maxlvl%2!=1)
                        reverse(tmp.begin(), tmp.end());
                    res.push_back(tmp);
                }
                tmp.clear();

            }

            tmp.push_back(t.second->val);
            if(t.second->left) Q.push(make_pair(t.first+1, t.second->left));
            if(t.second->right) Q.push(make_pair(t.first+1, t.second->right));
        }

        if(tmp.size() > 0)
        {
            if(maxlvl%2!=0)reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }

        return res;
    }
};
