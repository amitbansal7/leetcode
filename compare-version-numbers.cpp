//Runtime: 3 ms
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;

        while(i < version1.size() || j < version2.size())
        {
            int one = 0;
            int two = 0;

            while(i < version1.size() && version1[i] != '.')
                one = one*10 + version1[i++] - '0';

            while(j < version2.size() && version2[j] != '.')
                two = two*10 + version2[j++] - '0';

            if(one > two)
                return 1;
            else if(one < two)
                return -1;

            i++;j++;
        }

        return 0;

    }
};
