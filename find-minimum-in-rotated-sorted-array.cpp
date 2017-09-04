//Runtime: 13 ms
//My solution
class Solution {
public:
    int mina = INT_MAX;
    int sz;
    int findpivot(int lo, int hi, vector <int>nums)
    {
        if(lo>hi)
            return -1;
        int mid = lo + (hi-lo)/2;
        if(nums[mid] < mina)
            mina = nums[mid];

        int l = nums[mid-1];
        int r = nums[mid+1];

        if((nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) || (nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1]))
           return mid;


        int a = findpivot(lo, mid-1, nums);
        int b = findpivot(mid+1,hi, nums);

        return a>b?a:b;
    }

    int findMin(vector<int>& nums) {
        sz = nums.size();
        if(sz == 1)
            return nums[0];
        if(nums[0] < nums[sz-1])
            return nums[0];

        int a = findpivot(0,nums.size()-1, nums);

        if(a == -1)
            return min(nums[0], nums[sz-1]);


        return min(min(mina,a+1<sz?nums[a+1]:INT_MAX),min(a-1>=0?nums[a-1]:INT_MAX, nums[a]));
    }
};

//*************************************************************************************************
//Optimal solution
//Runtime: 6 ms
class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();

        int lo = 0;
        int hi  = sz-1;

        while(lo<hi)
        {
            int mid = lo + (hi-lo)/2;

            if(nums[mid] < nums[hi])
                hi = mid;
            else
                lo = mid+1;
        }
        //hi = lo after this
        return nums[hi];
    }
};
