//Runtime: 62 ms
class Solution {
public:

    TreeNode* solve(vector<int>&nums, int x, int y)
    {
        if (x > y)
            return NULL;
        int maxn = INT_MIN;
        int maxi = -1;
        for (int i = x; i <= y; i++)
        {
            if (maxn < nums[i])
            {
                maxn = nums[i];
                maxi = i;
            }
        }

        TreeNode* node = new TreeNode(nums[maxi]);
        node->left = solve(nums, x, maxi - 1);
        node->right = solve(nums, maxi + 1, y);
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};
