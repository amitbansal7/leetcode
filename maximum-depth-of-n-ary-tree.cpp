//Runtime: 60 ms
class Solution {
public:
	int maxDepth(Node* root) {
		if (root == NULL) return 0;

		int n = 0;
		for (Node* ch : root->children) {
			n = max(n, maxDepth(ch));
		}

		return n + 1;
	}
};