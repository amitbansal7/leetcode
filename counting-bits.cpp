//Runtime: 74 ms
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res;

        for (int i = 0; i <= num; i++) {
            int t = i;
            int c = 0;
            while (t) {
                t = t & (t - 1);
                c++;
            }
            res.push_back(c);
        }
        return res;
    }
};

//Runtime: 70 ms
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res(num+1, 0);

        for(int i=1;i<=num;i++){
            res[i] = res[i&(i-1)]+1;
        }
        return res;
    }
};
