//Runtime: 3 ms
class MapSum {
public:
    struct TrieNode
    {
        int score;
        bool isLeaf;
        struct TrieNode* children[26];
    };
    struct TrieNode* root = NULL;
    struct TrieNode* NewNode()
    {
        struct TrieNode* newNode = new TrieNode;
        newNode->isLeaf = 0;
        newNode->score = 0;
        for(int i=0;i<26;i++)
            newNode->children[i] = NULL;
        return newNode;
    }

    MapSum() {
        root = NewNode();
    }

    void insert(string key, int val) {

        struct TrieNode* crawl = root;

        for(char c:key)
        {
            if(!crawl->children[c-'a'])
                crawl->children[c-'a'] = NewNode();

            crawl->children[c-'a']->score  += val;

            crawl = crawl->children[c-'a'];
        }

        if(crawl->isLeaf)
        {
            crawl = root;
            for(char c:key)
            {
                crawl->children[c-'a']->score = val;
                crawl = crawl->children[c-'a'];
            }
        }
        else
        {
            crawl->isLeaf = 1;
        }
    }

    int sum(string prefix) {
        struct TrieNode* crawl = root;

        for(int i=0;i<prefix.size();i++)
        {
            if(crawl->children[prefix[i] - 'a'])
                crawl = crawl->children[prefix[i] - 'a'];
            else
                return 0;
        }

        return crawl->score;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
