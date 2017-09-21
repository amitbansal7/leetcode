//Runtime: 3 ms
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;

        queue<pair<int,TreeNode*> > Q;
        Q.push(make_pair(0, root));
        int maxlvl = 0;
        vector<int> tmp;

        while(!Q.empty())
        {
            pair<int, TreeNode* > t = Q.front();
            Q.pop();

            if(t.first > maxlvl)
            {
                if(tmp.size() > 0)
                {
                    res.push_back(tmp);
                    tmp.clear();
                }
                maxlvl++;
            }

            tmp.push_back(t.second->val);

            if(t.second->left) Q.push(make_pair(t.first+1, t.second->left));
            if(t.second->right) Q.push(make_pair(t.first+1, t.second->right));
        }

        if(tmp.size() > 0)
            res.push_back(tmp);
        reverse(res.begin(), res.end());

        return res;
    }
};
