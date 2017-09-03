//Runtime: 6 ms

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ::iterator it;
        int ans = 0;
        for(it=nums.begin();it!=nums.end();it++)
            if(*it != val)
                nums[ans++] = *it;

        return ans;

    }
};
