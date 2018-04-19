//Runtime: 13 ms
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j = 0;
        for(int i=0;i<nums.size() && i<=j;i++){
            j = max(j, i+nums[i]);
        }
        return j >= (nums.size()-1);
    }
};