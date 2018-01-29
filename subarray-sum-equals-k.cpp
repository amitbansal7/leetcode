//Runtime: 39 ms
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>mp;
        mp[0] = 1;
        int res = 0, sum = 0;
        for (int a : nums) {
            sum += a;
            if (mp.find(sum - k) != mp.end()) {
                res += mp[sum - k];
            }
            mp[sum]++;
        }
        return res;
    }
};

//Runtime: 491 ms
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k)
                    res++;
            }
        }
        return res;
    }
};
