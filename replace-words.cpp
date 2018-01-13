//Runtime: 68 ms
class Solution {
public:
    struct TrieNode {
        bool isLeaf;
        string word;
        struct TrieNode* children[26];

        TrieNode() {
            isLeaf = false;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    void add(string word, struct TrieNode* root) {
        for (char c : word) {
            if (root->children[c - 'a'] == NULL) {
                root->children[c - 'a'] = new TrieNode();
            }
            root = root->children[c - 'a'];
        }
        root->isLeaf = 1;
        root->word = word;
    }

    string find(struct TrieNode* root, string word) {

        for (char c : word) {
            root = root->children[c - 'a'];
            if (!root)
                return "";

            if (root->isLeaf)
                return root->word;
        }
        return "";
    }

    string replaceWords(vector<string>& dict, string sentence) {
        struct TrieNode* root = new TrieNode();
        for (string w : dict) {
            add(w, root);
        }
        string res = "";
        string t;

        for (char c : sentence) {
            if (c == ' ') {
                string temp = find(root, t);
                if (temp != "")
                    res += temp + ' ';
                else {
                    res += t + ' ';
                }
                t.clear();
            } else {
                t += c;
            }
        }
        string temp = find(root, t);
        if (temp != "")
            res += temp + ' ';
        else {
            res += t + ' ';
        }
        res.pop_back();
        return res;
    }
};
