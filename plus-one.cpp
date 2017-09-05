//Runtime: 6 ms
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size();
        int i = l-1;
        if(digits[l-1] <= 8)
            digits[l-1] = digits[l-1]+1;
        else
        {
            digits[i] = 0;
            if(i-1 < 0)
            {
                digits.insert(digits.begin(),1);
                return digits;
            }

            digits[i-1] += 1;
            while(digits[i-1] == 10)
            {

                digits[i-1] = 0;
                i--;
                if(i-1 < 0)
                {
                    digits.insert(digits.begin(),1);
                    return digits;
                }
                digits[i-1] = digits[i-1] + 1;
            }
        }

        return digits;
    }
};
