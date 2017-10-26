//Runtime: 8 ms
class Solution {

	public ListNode merge(ListNode a, ListNode b) {
		ListNode ret = new ListNode(-1);
		ListNode ans = ret;

		while (a != null && b != null) {
			if (a.val <= b.val) {
				ans.next = a;
				a = a.next;
			}

			else {
				ans.next = b;
				b = b.next;
			}
			ans = ans.next;
		}

		if (a != null)
			ans.next = a;
		else
			ans.next = b;

		return ret.next;
	}

	public ListNode sortList(ListNode head) {
		if (head == null || head.next == null)
			return head;

		ListNode slow = head;
		ListNode fast = head;
		ListNode prev = null;
		while (fast != null && fast.next != null) {
			prev = slow;
			slow = slow.next;
			fast = fast.next.next;
		}

		ListNode a = head;
		ListNode b = slow.next;
		prev.next = null;

		a = sortList(head);
		b = sortList(slow);

		return merge(a, b);
	}
}
