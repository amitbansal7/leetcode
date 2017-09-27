//Runtime: 19 ms
class Solution {
public:
    int reverse(int x) {
        bool minus = 0;
        if(x<1)
            minus = 1;

        x = abs(x);
        string str = to_string(x);
        int l = 0;
        int h = str.size()-1;

        while(l<h)
        {
            char t = str[l];
            str[l] = str[h];
            str[h] = t;
            l++;h--;
        }

        long long int newx = stoll(str);

        if(newx > INT_MAX)  return 0;

        if(minus)   newx = -newx;

        return newx;
    }
};
