//Runtime: 59 ms
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int x = nums1.size();
        int y = nums2.size();

        int lo = 0;
        int hi = x;

        while (lo <= hi) {
            int parX = lo + (hi - lo) / 2;
            int parY = (x + y + 1) / 2 - parX;

            int maxLeftX = (parX == 0) ? INT_MIN : nums1[parX - 1];
            int minRightX = (parX == x) ? INT_MAX : nums1[parX];

            int maxLeftY = (parY == 0) ? INT_MIN : nums2[parY - 1];
            int minRightY = (parY == y) ? INT_MAX : nums2[parY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    return ((double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))) / 2;
                }
                else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                hi = parX - 1;
            }
            else {
                lo = parX + 1;
            }
        }
        return -1;
    }
};
