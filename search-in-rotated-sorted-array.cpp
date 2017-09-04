//Runtime: 15 ms
//My solution
class Solution {
public:
    int binary(int i,int j,vector<int>nums,int find)
    {
        while(i<=j)
        {
            int mid = i + (j-i)/2;

            if(nums[mid] > find)
                j = mid-1;
            else if(nums[mid] < find)
                i = mid+1;
            else
                return mid;
        }
        return -1;
    }
    int findpivot(int lo, int hi, vector<int>nums)
    {
        if(lo>hi)
            return -1;

        int mid = lo + (hi-lo)/2;
        if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1] || nums[mid] > nums[mid+1] && nums[mid] < nums[mid-1])
            return mid;

        int a = findpivot(mid+1,hi, nums);
        int b = findpivot(lo,mid-1, nums);
        return a>b?a:b;
    }
    int search(vector<int>& nums, int target) {

        if(nums.size() < 1)
            return -1;

        int lo = 0;
        int hi = nums.size()-1;

        int pivot = findpivot(lo,hi,nums);

        int a = binary(pivot, nums.size()-1, nums,target);
        int b = binary(0,pivot-1, nums,target);

        return a>b?a:b;

    }
};

//****************************************************************

//Optimal solution
//Runtime: 3 ms
class Solution {
public:

    int search(vector<int>& nums, int target) {

        if(nums.size() < 1)
            return -1;

        int lo = 0;
        int hi = nums.size()-1;

        while(lo < hi)
        {
            int mid = lo + (hi-lo)/2;

            if(nums[mid] == target)
                return mid;

            else if(target < nums[mid])
            {
                if(nums[lo] <=  nums[mid] && nums[lo] > target)
                    lo = mid+1;
                else
                    hi = mid-1;
            }
            else
            {
                if(nums[hi] >= nums[mid] && nums[hi] < target)
                    hi = mid-1;
                else
                    lo = mid+1;
            }
        }

        return nums[lo] == target ? lo : -1;
    }
};
