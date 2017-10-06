//Runtime: 12 ms
class Solution {
private:
    static bool cmp(int a, int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(),cmp);
        string s;

        for(int a:nums)
            s += to_string(a);

        return s[0] == '0'?"0":s;
    }
};
