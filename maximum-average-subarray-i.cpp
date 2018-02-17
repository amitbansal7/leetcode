class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double temp = 0;
        double res = INT_MIN;
        for (int i = 0; i < k; i++)
            temp += nums[i];
        res = max(res, temp / k);
        for (int i = k; i < nums.size(); i++) {
            res = max(res, temp / k);
            temp -= nums[i - k];
            temp += nums[i];
        }
        res = max(res, temp / k);
        return res;
    }
};
