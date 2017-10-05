//Runtime: 13 ms
//Learned from discuss section.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        if(nums.size() > 1)
        {
            while(slow!=fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            int fast = 0;
            while(slow!=fast)
            {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;
    }
};
