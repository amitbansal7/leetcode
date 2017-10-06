//Runtime: 3 ms
class Solution {
public:

    void solve(vector<vector<int > >&res, vector<int> temp, int start, int l, int s, int k, int n)
    {
        if(l == k && s == n)
            res.push_back(temp);

        if(l >= k)
            return;

        for(int i=start;i<=9;i++)
        {
            temp.push_back(i);
            solve(res, temp, i+1, l+1, s+i, k, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> temp;
        vector<vector<int> > res;
        solve(res, temp, 1, 0, 0, k, n);
        return res;
    }
};
