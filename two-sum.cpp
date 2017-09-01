class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out;

        map<int,int>mymap;

        for(int i=0;i<nums.size();i++)
        {
            if(mymap.find(target-nums[i]) != mymap.end())
            {
                out.push_back(mymap[target-nums[i]]);
                out.push_back(i);
                return out;
            }
            mymap[nums[i]] = i;
        }

        return out;
    }
};
