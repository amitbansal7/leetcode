//Runtime: 6 ms
class Solution {
public:

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> M;

        for (int a : nums2)
            M[a]++;

        for (int a : nums1)
            if (M.find(a) != M.end())
            {
                if (M[a] >= 1)
                {
                    res.push_back(a);
                    M[a]--;
                }
            }

        return res;

    }
};

//Runtime: 6 ms
class Solution {
public:

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i, j;
        i = j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i++]);
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return res;
    }
};
