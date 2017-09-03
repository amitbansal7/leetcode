//Runtime: 29 ms
// O(n) memory, O(n) space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> S;
        for(auto it:nums)
            S.insert(it);
        vector<int> q(S.begin(),S.end());
        nums = q;
        return S.size();
    }
};

//Runtime: 49 ms
// O(n) memory, O(1) space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        vector<int>::iterator it;
        int n = nums.size();
        if( n== 0)
            return 0;
        for(it=nums.begin()+1;it!=nums.end();it++)
            while(*it == *(it-1))
            {
                n--;
                nums.erase(it-1);
                if(it == nums.end())
                    return n;
            }
        return n;
    }
};

//Runtime: 28 ms
// O(n) memory, O(1) space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if(n < 2) return n;
        int idx = 1;

        for(int i=1;i<n;i++)
            if(nums[i] != nums[i-1])
                nums[idx++] = nums[i];

        return idx;
    }
};
