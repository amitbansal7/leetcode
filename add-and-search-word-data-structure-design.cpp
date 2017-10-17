//Runtime: 79 ms
class WordDictionary {
public:
    /** Initialize your data structure here. */

    typedef struct TrieNode
    {
        int isLeaf;
        struct TrieNode* children[26];
    }TrieNode;

    TrieNode* root = NULL;

    TrieNode* NewNode()
    {
        TrieNode* newNode = new TrieNode;
        newNode->isLeaf = 0;
        for(int i=0;i<26;i++)
            newNode->children[i] = NULL;
        return newNode;
    }

    WordDictionary() {
        root = NewNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {

        TrieNode* crawl = root;

        for(char c:word)
        {
            if(!crawl->children[c-'a'])
                crawl->children[c-'a'] = NewNode();

            crawl = crawl->children[c-'a'];
        }
        crawl->isLeaf = 1;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */

    bool searchHelp(string word, TrieNode* crawl)
    {
        if(!crawl)
            return 0;

        for(int c=0;c<word.size();c++)
        {
            if(word[c] == '.')
            {
                for(int i=0;i<26;i++)
                    if(searchHelp(word.substr(c+1), crawl->children[i]))
                        return 1;

                return 0;
            }
            else
            {
                if(!crawl->children[word[c]-'a'])
                    return 0;
            }
            crawl = crawl->children[word[c]-'a'];
        }

        return crawl->isLeaf;
    }

    bool search(string word) {
        TrieNode* crawl = root;
        return searchHelp(word, crawl);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
