//Runtime: 51 ms
class Solution {
public:

    struct TrieNode {
        bool isLeaf;
        string word;
        struct TrieNode* children[26];

        TrieNode() {
            isLeaf = false;
            word = "";
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    string res = "";
    void add(string word, struct TrieNode* root) {
        struct TrieNode* crawl = root;

        for (char c : word) {
            if (crawl->children[c - 'a'] == NULL) {
                crawl->children[c - 'a'] = new TrieNode();
            }
            crawl = crawl->children[c - 'a'];
        }
        crawl->word = word;
        crawl->isLeaf = 1;
    }

    void solve(struct TrieNode* root) {
        if (!root || !root->isLeaf)  return;

        if (res.size() < root->word.size()) {
            res = root->word;
        } else {
            res = min(res, root->word);
        }

        for (int i = 0; i < 26; i++) {
            solve(root->children[i]);
        }
    }
    string longestWord(vector<string>& words) {
        struct TrieNode* root = new TrieNode();
        for (string word : words) {
            add(word, root);
        }
        for (int i = 0; i < 26; i++) {
            solve(root->children[i]);
        }
        return res;
    }
};
