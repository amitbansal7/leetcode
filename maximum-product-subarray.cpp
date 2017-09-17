//Optimal Solution
//Runtime: 3 ms
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int amax,amin,ans;
        ans = amax = amin = nums[0];

        for(int i=1;i<n;i++)
        {
            if(nums[i] < 0)
                swap(amax, amin);

            amax = max(nums[i], nums[i]*amax);
            amin = min(nums[i], nums[i]*amin);

            ans = max(ans, amax);
        }
        return ans;
    }
};



//Not accepted because of large memory consumption
//My solution
//Runtime error O(n^2) space and memory
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int DP[n+1][n+1];

        int ans = INT_MIN;

        for(int i=0;i<n;i++)
        {
            DP[i][i] = nums[i];
            ans = max(ans, nums[i]);
        }

        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j = i+l-1;

                DP[i][j] = DP[i][j-1] * nums[j];
                ans = max(ans, DP[i][j]);
            }
        }

        return ans;
    }
};

