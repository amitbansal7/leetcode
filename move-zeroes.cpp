//Runtime: 16 ms
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z = 0;
        int ans = 0;
        for(auto it:nums)
        {
            if(it != 0)
                nums[ans++] = it;
            else
                z++;
        }
        while(z--)
            nums[ans++] = 0;
    }
};
