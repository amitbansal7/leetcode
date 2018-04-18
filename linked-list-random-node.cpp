//Runtime: 48 ms
class Solution {
public:
	/** @param head The linked list's head.
	    Note that the head is guaranteed to be not null, so it contains at least one node. */
	ListNode* thead;
	int n = 0;
	Solution(ListNode* head) {
		thead = head;
		ListNode* trav = head;
		while (trav) {
			n++;
			trav = trav->next;
		}
	}

	/** Returns a random node's value. */
	int getRandom() {
		ListNode* trav = thead;
		int res;
		for (int i = 0; trav; i++) {
			if (rand() % (i + 1) == i) res = trav->val;
			trav = trav->next;
		}
		return res;
	}
};
