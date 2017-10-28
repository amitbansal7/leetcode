//Runtime: 32 ms
class Solution {
public:

    string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*> > &Mp)
    {
        if(!root)
            return "";

        string s = "(" + serialize(root->left, Mp) + to_string(root->val) + serialize(root->right, Mp) + ")";
        Mp[s].push_back(root);
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode* > res;
        unordered_map<string, vector<TreeNode* > > Mp;
        serialize(root, Mp);

        for(auto it:Mp)
        {
            if(it.second.size() > 1)
                res.push_back(it.second[0]);
        }
        return res;
    }
};
