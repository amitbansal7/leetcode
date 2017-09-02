class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >ans;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            int sum = -nums[i];
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int lo = i+1;
            int hi = len-1;

            while(lo<hi)
            {
                if(nums[lo] + nums[hi] == sum)
                {
                    vector<int>t;
                    t.push_back(nums[i]);
                    t.push_back(nums[lo]);
                    t.push_back(nums[hi]);
                    ans.push_back(t);

                    while(lo<hi && nums[lo] == nums[lo+1])
                        lo++;
                    while(lo<hi && nums[hi] == nums[hi-1])
                        hi--;
                    lo++;
                    hi--;
                }
                else if(nums[lo] + nums[hi] < sum)
                    lo++;
                else
                    hi--;

            }
        }
        return ans;
    }
};
