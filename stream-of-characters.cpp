// Runtime: 276 ms
// Memory Usage: 99.7 MB
class StreamChecker {
public:

  struct Node {
    bool word;
    vector<Node*> children;

    Node() {
      word = false;
      children = vector<Node*>(26, NULL);
    }
  };

  Node* root = NULL;
  string str = "";
  StreamChecker(vector<string>& words) {
    root = new Node();

    for (string s : words) {
      Node* crawl = root;
      for (int i = s.size() - 1; i >= 0; i--) {
        if (!crawl->children[s[i] - 'a']) {
          crawl->children[s[i] - 'a'] = new Node();
        }
        crawl = crawl->children[s[i] - 'a'];
      }
      crawl->word = true;
    }

  }

  bool query(char letter) {
    str += letter;
    Node* crawl = root;
    for (int i = str.size() - 1; i >= 0; i--) {
      if (!crawl->children[str[i] - 'a']) return false;
      crawl = crawl->children[str[i] - 'a'];
      if (crawl->word) return true;
    }
    return false;
  }
};