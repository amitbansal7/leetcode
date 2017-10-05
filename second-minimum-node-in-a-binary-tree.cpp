//Runtime: 3 ms
class Solution {
public:

    void inorder(TreeNode* root, set<int>&nums)
    {
        if(!root)
            return;

        inorder(root->left, nums);
        nums.insert(root->val);
        inorder(root->right, nums);
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> nums;
        inorder(root, nums);

        if(nums.size() < 2)
            return -1;

        return *(++nums.begin());
    }
};
