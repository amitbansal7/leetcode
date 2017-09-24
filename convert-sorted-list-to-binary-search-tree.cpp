//Runtime: 22 ms
class Solution {
public:

    TreeNode* insert(TreeNode* root, int val)
    {
        if(!root)
            return new TreeNode(val);
        else if(root->val < val)
            return root->right = insert(root->right, val);
        else
            return root->left = insert(root->left, val);
    }

    TreeNode* MakeBST(TreeNode* root, int l,int h, vector<int> &nums)
    {
        if(l>h)
            return NULL;

        int mid = (l+h)/2;
        root = insert(root, nums[mid]);

        root->right = MakeBST(root, mid+1, h, nums);
        root->left = MakeBST(root, l, mid-1, nums);

        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;

        while(head!=NULL)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        return MakeBST(NULL, 0, nums.size()-1, nums);
    }
};
