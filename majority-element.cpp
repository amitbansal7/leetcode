//Runtime: 19 ms
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int c = 1;

        for(int i=1;i<nums.size();i++)
        {
            if(c == 0)
            {
                c++;
                ans = nums[i];
            }
            else if(nums[i] == ans)
                c++;
            else
                c--;
        }
        return ans;
    }
};
