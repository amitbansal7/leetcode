//Runtime: 73 ms
class Solution {
public:

    void solve(vector<vector<int> > &res, vector<int>&temp, int l, int c, int k,int n)
    {
        if(c == k)
        {
            res.push_back(temp);
            return;
        }

        for(int i=l;i<=n;i++)
        {
            temp.push_back(i);
            solve(res, temp, i+1,c+1, k, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int>temp;
        solve(res, temp, 1, 0, k, n);
        return res;
    }
};
