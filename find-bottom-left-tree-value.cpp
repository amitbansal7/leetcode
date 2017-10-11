//Using level order traversal
//Runtime: 9 ms
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res;
        vector<int>temp;

        queue<pair<int,TreeNode* > >Q;
        Q.push(make_pair(1, root));
        int maxlvl = 0;
        while(!Q.empty())
        {
            pair<int, TreeNode* > t = Q.front();
            Q.pop();

            if(t.first > maxlvl)
            {
                maxlvl++;
                if(temp.size() > 0)
                {
                    res = temp[0];
                    temp.clear();
                }
            }
            temp.push_back(t.second->val);

            if(t.second->left)
                Q.push(make_pair(t.first+1, t.second->left));

            if(t.second->right)
                Q.push(make_pair(t.first+1, t.second->right));
        }

        if(temp.size() > 0)
            res = temp[0];

        return res;
    }
};

//Runtime: 9 ms
//Better solution
class Solution {
public:
    void solve(TreeNode* root, int lvl, pair<int,int> &res)
    {
        if(!root)
            return;
        solve(root->left, lvl+1, res);
        solve(root->right, lvl+1, res);
        if(lvl > res.first)
        {
            res.second = root->val;
            res.first = lvl;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        pair<int,int>res;
        res.first = res.second = 0;
        solve(root, 1, res);
        return res.second;
    }
};
