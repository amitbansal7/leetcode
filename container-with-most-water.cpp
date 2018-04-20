//Runtime: 19 ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0;
        int hi = height.size() - 1;
        int res = INT_MIN;
        while (lo < hi) {
            res = max(res, (hi - lo) * min(height[hi], height[lo]));

            if (height[lo] < height[hi])
                lo++;
            else
                hi--;
        }
        return res;
    }
};