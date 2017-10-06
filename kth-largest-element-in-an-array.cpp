//Runtime: 9 ms
class Solution {
public:

    void MaxHeapify(vector<int>&nums, int i)
    {
        int l = 2*i + 1;
        int r = 2*i + 2;

        int largest = i;

        if(l < nums.size() && nums[l] > nums[largest])
            largest = l;

        if(r < nums.size() && nums[r] > nums[largest])
            largest = r;

        if(largest!=i)
        {
            swap(nums[i], nums[largest]);
            MaxHeapify(nums, largest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        for(int i=n/2-1;i>=0;i--)
            MaxHeapify(nums, i);

        for(int i=0;i<k-1;i++)
        {
            nums[0] = INT_MIN;
            MaxHeapify(nums, 0);
        }

        return nums[0];
    }
};
