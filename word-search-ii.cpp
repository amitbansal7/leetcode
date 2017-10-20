//Runtime: 39 ms
class Solution {
public:
    vector<string>res;
    struct TrieNode
    {
        struct TrieNode* children[26];
        string word;
    };

    TrieNode* NewNode()
    {
        TrieNode* node = new TrieNode;
        node->word = "";
        for(int i=0;i<26;i++)
            node->children[i] = NULL;
        return node;
    }

    struct TrieNode* BuildTrie(vector<string>&words)
    {
        struct TrieNode* root = NewNode();
        for(string word:words)
        {
            TrieNode* crawl = root;
            for(char c:word)
            {
                if(crawl->children[c-'a'] == NULL)
                    crawl->children[c-'a'] = NewNode();

                crawl = crawl->children[c-'a'];
            }
            crawl->word = word;
        }

        return root;
    }


    void solve(vector<vector<char> > &board, int i, int j, struct TrieNode* trie)
    {
        char c = board[i][j];
        if(c == '$' || !trie->children[c-'a'])
            return;

        trie = trie->children[c-'a'];

        if(trie->word != "")
        {
            res.push_back(trie->word);
            trie->word = "";
        }

        board[i][j] = '$';

        if(i>0)
            solve(board, i-1, j, trie);
        if(i<board.size()-1)
            solve(board, i+1, j, trie);
        if(j >0)
            solve(board, i, j-1, trie);

        if(j<board[0].size() - 1)
            solve(board, i, j+1, trie);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        struct TrieNode* trie = BuildTrie(words);

        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                solve(board, i, j, trie);
        return res;
    }
};
