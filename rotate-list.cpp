//Runtime: 9 ms
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* nhead = head;
		if (!head || !head->next)
			return head;
		ListNode* th = head;
		int c = 0;
		while (th)
		{
			th = th->next;
			c++;
		}
		k = k % c;
		for (int i = 0; i < k; i++)
			nhead = nhead->next;

		ListNode* t = head;

		while (nhead && nhead->next != NULL)
		{
			t = t->next;
			nhead = nhead->next;
		}

		nhead->next = head;
		ListNode* ans = t->next;
		t->next = NULL;
		return ans;
	}
};
