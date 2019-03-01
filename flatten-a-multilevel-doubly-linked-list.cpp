// Runtime: 112 ms
// Memory Usage: 31.1 MB
class Solution {
public:
  Node* flatten(Node* head) {
    if (!head) return head;

    Node* crawl = head;
    while (crawl) {
      if (!crawl->child) {
        crawl = crawl->next;
        continue;
      }

      Node* tchild = crawl->child;
      while (tchild->next) {
        tchild = tchild->next;
      }

      tchild->next = crawl->next;

      if (crawl->next)
        crawl->next->prev = tchild;

      crawl->next = crawl->child;
      crawl->child->prev = crawl;
      crawl->child = NULL;

    }
    return head;
  }
};