//Runtime: 2 ms
class Solution {

    private int[] solve(TreeNode root)
    {
        if(root == null)
            return new int[2];

        int[] left = solve(root.left);
        int[] right = solve(root.right);

        int[] res = new int[2];

        res[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        res[1] = root.val + left[0] + right[0];

        return res;
    }

    public int rob(TreeNode root) {
        int[] res = solve(root);
        return Math.max(res[0], res[1]);
    }
}
