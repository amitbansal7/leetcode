//Runtime: 6 ms
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int lo = 0;
        int hi = numbers.size()-1;
        vector<int> res;

        while(lo < hi)
        {
            if(numbers[lo]+numbers[hi] == target)
            {
                res.push_back(lo+1);
                res.push_back(hi+1);
                return res;
            }
            else if(numbers[lo] + numbers[hi] < target)
                lo++;
            else
                hi--;
        }

    }
};
