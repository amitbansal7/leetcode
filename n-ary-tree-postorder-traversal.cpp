//Runtime: 44 ms
class Solution {
public:

    void solve(vector<int> &res, Node* root) {
        for (Node* ch : root->children) {
            solve(res, ch);
        }
        res.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root != NULL) {
            solve(res, root);
        }
        return res;
    }
};