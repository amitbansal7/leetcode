//Runtime: 6 ms
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int lo = 0;
        int sz = nums.size();
        if(sz==0)
            return 0;
        if(sz==1)
            return nums[0]<target;

        if(nums[0] > target)
            return 0;

        if(nums[sz-1] < target)
            return sz;


        int hi = sz-1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;

            if(nums[mid] == target)
                return mid;

            else if(nums[mid] > target && nums[mid-1] < target)
                return mid;

            else if(nums[mid] < target && nums[mid+1] > target)
                return mid+1;

            else if(nums[mid] > target)
                hi = mid-1;
            else
                lo = mid+1;
        }

    }
};
