//Runtime: 16 ms
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root)
    {

        vector<double>res;
        if(!root)
            return res;
        queue<pair<int,TreeNode*> > Q;

        Q.push(make_pair(1, root));
        int maxlvl = 0;
        vector<int>temp;

        while(!Q.empty())
        {
            pair<int,TreeNode*> t = Q.front();
            Q.pop();

            if(t.first > maxlvl)
            {
                maxlvl++;
                if(temp.size() > 0)
                {
                    double sum = 0.0;
                    for(int a : temp)
                        sum += a;

                    res.push_back(sum/temp.size());
                }
                temp.clear();

            }
            temp.push_back(t.second->val);

            if(t.second->left)
                Q.push(make_pair(t.first+1, t.second->left));

            if(t.second->right)
                Q.push(make_pair(t.first+1, t.second->right));

        }
        if(!temp.empty())
        {
            double sum = 0;
            for(int a:temp)
                sum += a;
            res.push_back(sum/temp.size());
        }
        return res;
    }
};
