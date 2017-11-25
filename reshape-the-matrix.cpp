//Runtime: 43 ms
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>>res;
        int m = nums.size();
        if (m == 0)
            return nums;
        int n = nums[0].size();

        if (m * n != r * c)
            return nums;

        vector<int>t;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                t.push_back(nums[i][j]);
                if (t.size() == c)
                {
                    res.push_back(t);
                    t.clear();
                }
            }
        return res;
    }
};
