//Runtime: 9 ms
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int msf = INT_MIN;
        int meh = 0;

        for(int i=0;i<nums.size();i++)
        {
            meh += nums[i];
            if(msf < meh)
                msf = meh;

            if(meh < 0)
                meh = 0;
        }
        return msf;
    }
};

//***************************************************************
//Runtime: 6 ms
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if(nums.size() < 1)
            return INT_MIN;

        int msf = nums[0];
        int meh = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            meh = max(nums[i], meh + nums[i]);
            msf = max(msf,meh);
        }
        return msf;
    }
};
