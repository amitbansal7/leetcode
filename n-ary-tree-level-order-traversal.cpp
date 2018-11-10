//Runtime: 44 ms
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }

        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 1));

        vector<int> temp;
        int lvl = 0;
        while (!q.empty()) {

            pair<Node*, int> t = q.front();
            q.pop();

            if (t.second > lvl) {
                if (temp.size() > 0) {
                    res.push_back(temp);
                    temp.clear();
                }
                lvl++;
            }
            temp.push_back(t.first->val);

            for (Node* ch : t.first->children) {
                q.push(make_pair(ch, t.second + 1));
            }
        }

        if (temp.size() > 0) {
            res.push_back(temp);
        }

        return res;

    }
};