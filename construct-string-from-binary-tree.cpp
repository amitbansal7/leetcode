//Runtime: 12 ms
class Solution {
public:
    void solve(TreeNode* root, string &s)
    {
        if(!root)
            return;

        s += to_string(root->val);
        if(root->left)
        {
            s+='(';
            solve(root->left, s);
            s+=')';
        }

        if(root->right)
        {
            if(!root->left)
            {
                s+='(';
                s+=')';
            }
            s+='(';
            solve(root->right, s);
            s+=')';
        }
    }
    string tree2str(TreeNode* t) {
        string s;
        solve(t,s);
        return s;
    }
};
