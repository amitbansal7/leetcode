class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        int n = nums.size();

        if(n == 0)
            return ans;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum = target - (nums[i] + nums[j]);
                int lo = j+1;
                int hi = n-1;

                while(lo < hi)
                {
                    int lohi = nums[lo] + nums[hi];
                    if(lohi < sum)
                        lo++;
                    else if(lohi > sum)
                        hi--;
                    else
                    {
                        vector<int> t(4,0);
                        t[0] = nums[i];
                        t[1] = nums[j];
                        t[2] = nums[lo];
                        t[3] = nums[hi];

                        ans.push_back(t);

                        while(lo<hi && nums[lo] == t[2])
                            lo++;

                        while(lo < hi && nums[hi] == t[3])
                            hi--;

                    }

                }
                while(j+1 < n && nums[j] == nums[j+1]) ++j;
            }
            while(i+1 < n && nums[i] == nums[i+1]) ++i;
        }
        return ans;
    }
};
