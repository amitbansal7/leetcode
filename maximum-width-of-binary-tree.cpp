//Runtime: 3 ms
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (!root)
            return 0;

        queue<pair<TreeNode*, int> >Q;
        Q.push(make_pair(root, 1));
        int ans = 0;

        while (!Q.empty())
        {
            int l = Q.front().second;
            int r = l;

            int n = Q.size();
            for (int i = 0; i < n; i++)
            {
                r = Q.front().second;
                TreeNode* t = Q.front().first;
                Q.pop();
                if (t->left)
                    Q.push(make_pair(t->left, 2 * r));
                if (t->right)
                    Q.push(make_pair(t->right, 2 * r + 1));
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
