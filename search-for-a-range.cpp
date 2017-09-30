//Runtime: 9 ms
class Solution {
public:
    int li = -1;
    int ri = -1;
    bool lf = 0,rf= 0;

    void binary(vector<int>&nums, int l, int h, int target)
    {
        int mid;
        if(lf&&rf)
            return;

        while(l<=h)
        {
            mid = l + (h-l)/2;
            if(nums[mid] == target)
            {

                if(mid+1 >= nums.size() || nums[mid+1] > nums[mid])
                {
                    ri = mid;
                    rf = 1;
                    if(!lf)
                        binary(nums, l, mid-1, target);

                    return;
                }
                else if(mid-1 < 0 || nums[mid-1] < nums[mid])
                {
                    li = mid;
                    lf = 1;
                    if(!rf)
                        binary(nums, mid+1, h, target);

                    return;
                }
                else
                {
                    binary(nums, l, mid-1, target);
                    binary(nums, mid+1, h, target);
                    return;
                }
            }
            else if(nums[mid] < target)
                l = mid+1;
            else
                h = mid -1;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res;
        binary(nums, 0, nums.size()-1, target);

        if(li == -1 && ri!=-1)
            li = ri;
        else if(ri == -1 && li!=-1)
            ri = li;
        res.push_back(li);
        res.push_back(ri);

        return res;

    }
};
