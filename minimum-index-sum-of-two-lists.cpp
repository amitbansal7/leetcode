//Runtime: 112 ms
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> M;

        for(int i=0;i<list1.size();i++)
            M[list1[i]] = i;

        int ans = INT_MAX;
        vector<string>res;

        for(int i=0;i<list2.size();i++)
        {
            if(M.find(list2[i]) != M.end())
            {
                if(M[list2[i]]+i < ans)
                {
                    res.clear();
                    res.push_back(list2[i]);
                    ans = M[list2[i]] + i;
                }
                else if(M[list2[i]]+i == ans)
                    res.push_back(list2[i]);
            }
        }
        return res;
    }
};
