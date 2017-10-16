//Runtime: 62 ms
class Trie {
public:
    /** Initialize your data structure here. */

    struct TrieNode
    {
        int isLeaf;
        struct TrieNode* children[26];
    };

    struct TrieNode* NewNode()
    {
        struct TrieNode* newNode = new TrieNode;
        newNode->isLeaf = false;
        for(int i=0;i<26;i++)
            newNode->children[i] = NULL;
        return newNode;
    }

    struct TrieNode* root;

    Trie() {
        root = NewNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        struct TrieNode* crawl = root;
        for(char c:word)
        {
            if(!crawl->children[c-'a'])
                crawl->children[c-'a'] = NewNode();

            crawl = crawl->children[c-'a'];
        }
        crawl->isLeaf = 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct TrieNode* crawl = root;
        for(char c:word)
        {
            if(!crawl->children[c-'a'])
                return 0;
            crawl = crawl->children[c-'a'];
        }
        return crawl->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct TrieNode* crawl = root;
        for(char c:prefix)
        {
            if(!crawl->children[c-'a'])
                return 0;
            crawl = crawl->children[c-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
