//Runtime: 2 ms
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int ans = Integer.MAX_VALUE;
        int n = nums.length;
        int l = 0;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            while(sum >= s)
            {
                ans = Math.min(ans, i+1-l);
                sum -= nums[l++];
            }
        }
        if(ans==Integer.MAX_VALUE)
            return 0;
        return ans;
    }
}
