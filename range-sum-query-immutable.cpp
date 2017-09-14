//Runtime: 39 ms
class NumArray {
public:
    vector<int>DP;
    NumArray(vector<int> nums) {
        int bk = 0;
        for(int i=0;i<nums.size();i++)
        {
            bk+=nums[i];
            DP.push_back(bk);
        }
    }

    int sumRange(int i, int j) {

        return DP[j] - ((i>0)?DP[i-1]:0);
    }
};
