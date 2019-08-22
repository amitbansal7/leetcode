// Runtime: 48 ms
// Memory Usage: 19.5 MB
class MyLinkedList {
public:

  class Node {
  public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
      this->val = val;
      this->next = NULL;
      this->prev = NULL;
    }
  };

  Node* head;
  Node* tail;
  int len;
  MyLinkedList() {
    head = new Node(-1);
    tail = new Node(-1);
    head->next = tail;
    tail->prev = head;
    len = 0;
  }


  /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
  int get(int index) {
    if (index >= len || index < 0) return -1;
    int i = 0;
    Node* crawl = head->next;
    while (i++ < index && crawl)
      crawl = crawl->next;
    if (!crawl) return -1;
    return crawl->val;
  }

  /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    Node* newNode = new Node(val);
    newNode->next = head->next;
    head->next->prev = newNode;
    newNode->prev = head;
    head->next = newNode;
    len++;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    Node* newNode = new Node(val);
    newNode->next = tail;
    newNode->prev = tail->prev;
    tail->prev->next = newNode;
    tail->prev = newNode;
    len++;
  }

  /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
  void addAtIndex(int index, int val) {
    if (index > len) {
      return;
    } else if (index < 0) {
      addAtHead(val);
    } else {
      int i = 0;
      Node* crawl = head->next;
      while (i++ < index && crawl)
        crawl = crawl->next;
      if (!crawl) return;
      Node* newNode = new Node(val);
      crawl->prev->next = newNode;
      newNode->next = crawl;
      newNode->prev = crawl->prev;
      crawl->prev = newNode;
      len++;
    }

  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (index >= len || index < 0) return;
    int i = 0;
    Node* crawl = head->next;
    while (i++ < index && crawl)
      crawl = crawl->next;

    if (!crawl) return;
    crawl->prev->next = crawl->next;
    crawl->next->prev = crawl->prev;
    len--;
  }
};