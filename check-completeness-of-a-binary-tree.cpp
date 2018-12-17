//Runtime: 4 ms - BFS
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool null = false;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();

            if (null && (p->left || p->right))
                return false;

            if (!p->left && p->right)
                return false;

            if (p->left) q.push(p->left); else null = true;
            if (p->right) q.push(p->right); else null = true;
        }
        return true;
    }
};

//Runtime: 4 ms
class Solution {
public:

    int count(TreeNode* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    bool check(TreeNode* root, int pos, int maxCount) {
        if (!root) return true;
        if (pos >= maxCount) return false;
        return check(root->left, pos * 2 + 1, maxCount) && check(root->right, pos * 2 + 2, maxCount);
    }

    bool isCompleteTree(TreeNode* root) {
        int maxCount = count(root);
        return check(root, 0, maxCount);
    }
};