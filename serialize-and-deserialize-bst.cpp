//Runtime: 29 ms
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        queue<TreeNode*> Q;
        Q.push(root);
        string s;
        int len;
        while(!Q.empty())
        {
            TreeNode* t = Q.front();
            Q.pop();

            if(t)
            {
                s += to_string(t->val) + ',';
                len = s.size();
            }

            else
                s += "#,";

            if(t)
            {
                Q.push(t->left);
                Q.push(t->right);
            }
        }
        s = s.substr(0, len-1);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> S;
        if(data.size()<=0)
            return NULL;

        for(int i=0;i<data.size();i++)
        {
            string s;
            while(i<data.size() && data[i] != ',')
                s += data[i++];
            S.push_back(s);
        }
        TreeNode* root;
        int i = 0;
        queue<TreeNode*> Q;
        root = new TreeNode(stoi(S[i++]));
        Q.push(root);
        while(!Q.empty() && i<S.size())
        {
            TreeNode* t = Q.front();
            Q.pop();

            if(S[i] != "#")
            {
                t->left = new TreeNode(stoi(S[i++]));
                Q.push(t->left);
            }
            else
                i++;

            if(i<S.size() && S[i] != "#")
            {
                t->right = new TreeNode(stoi(S[i++]));
                Q.push(t->right);
            }
            else
                i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
