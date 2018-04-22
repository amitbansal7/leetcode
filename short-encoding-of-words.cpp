//Runtime: 78 ms
class Solution {
public:

    class TrieNode {
    public:
        TrieNode* children[26];
        bool isLeaf;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                this->children[i] = nullptr;
            }
            isLeaf = false;
        }
    };

    TrieNode* root;

    void insert(string s) {
        TrieNode* crawl = root;
        for (char c : s) {
            if (!crawl->children[c - 'a']) {
                crawl->children[c - 'a'] = new TrieNode();
            }

            crawl = crawl->children[c - 'a'];
        }
    }

    int charCount = 0;

    void traverse(TrieNode* root, int count) {
        bool end = true;
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                end = false;
                traverse(root->children[i], count + 1);
            }
        }
        if (end) {
            charCount += count + 1;
        }
    }

    int minimumLengthEncoding(vector<string>& words) {
        root = new TrieNode();
        for (string s : words) {
            string t = s;
            reverse(t.begin(), t.end());
            insert(t);
        }
        traverse(root, 0);
        return charCount;
    }
};