//Runtime: 6 ms
// Using level order travesal
class Solution {
public:

    bool checkpal(vector<int>vec)
    {
        int lo = 0;
        int hi = vec.size()-1;

        while(lo<hi)
        {
            if(vec[lo] != vec[hi])
                return 0;

            lo++;
            hi--;
        }

        return 1;
    }
    bool isSymmetric(TreeNode* root) {

        int NULL_INT = INT_MIN;
        vector<vector<int> >res;
        TreeNode* NIL = new TreeNode(NULL_INT);
        if(!root) return 1;

        queue<pair<int, TreeNode*> >Q;
        Q.push(make_pair(0, root));
        int maxlvl = 0;

        vector<int> ch;

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


            if(t.second->left)
                Q.push(make_pair(t.first+1, t.second->left));
            else if(t.second->val != NULL_INT)
                Q.push(make_pair(t.first+1,NIL));

            if(t.second->right)
                Q.push(make_pair(t.first+1, t.second->right));
            else if(t.second->val != NULL_INT)
                Q.push(make_pair(t.first+1, NIL));

        }
        if(ch.size() > 0)
            res.push_back(ch);

        for(int i=0;i<res.size();i++)
            if(!checkpal(res[i]))
                return 0;

        return 1;
    }
};

//Learned From editorial.
//Runtime: 3 ms
class Solution {
public:

    bool checksym(TreeNode* lef, TreeNode* rig)
    {
        if(!lef && !rig)
            return 1;
        if(!lef || !rig)
            return 0;

        if(lef->val!=rig->val)
            return 0;

        return (checksym(lef->left,rig->right) && checksym(lef->right, rig->left));

    }
    bool isSymmetric(TreeNode* root) {

        if(!root)
            return 1;

        return checksym(root->left, root->right);
    }
};
