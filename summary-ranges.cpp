//Runtime: 0 ms
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string t;
        vector<string>temp;

        for(int i=0;i<nums.size();i++)
        {
            t = to_string(nums[i]);
            int ti = i;
            while(i+1<nums.size() && nums[i] == nums[i+1]-1)
                i++;

            if(ti != i)
            {
                t += "->";
                t +=  to_string(nums[i]);
            }

            temp.push_back(t);
        }
        return temp;
    }
};
