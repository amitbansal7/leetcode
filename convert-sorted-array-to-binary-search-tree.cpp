//Runtime: 13 ms
class Solution {
public:

    TreeNode* insert(TreeNode* root,int data)
    {
        if(!root)
            return new TreeNode(data);
        else if(root->val < data)
            return root->right = insert(root->right, data);
        else
            return root->left = insert(root->left, data);
    }

    TreeNode* MakeBST(TreeNode* root, int l, int h, vector<int> &nums)
    {
        if(l>h)
            return NULL;

        int mid = (l+h)/2;
        root = insert(root, nums[mid]);

        root->right = MakeBST(root, mid+1, h, nums);
        root->left = MakeBST(root, l,mid-1, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return MakeBST(NULL, 0, nums.size()-1, nums);
    }
};
