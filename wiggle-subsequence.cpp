//Runtime: 3 ms
//DP approach
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();

        if(len <= 1)
            return len;

        int up = 1;
        int dn = 1;

        for(int i=1;i<len;i++)
        {
            if(nums[i] < nums[i-1])
                dn = up+1;
            else if(nums[i] > nums[i-1])
                up = dn+1;
        }
        return max(up, dn);
    }
};

//Runtime: 3 ms
//Greedy approach
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();

        if(len <= 1)
            return len;

        int prev = nums[1] - nums[0];
        int count = prev?2:1;

        for(int i=2;i<len;i++)
        {
            int diff = nums[i] - nums[i-1];

            if((diff < 0 && prev >= 0 )||(diff >0 && prev <= 0))
            {
                count++;
                prev = diff;
            }
        }
        return count;
    }
};
