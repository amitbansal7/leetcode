//My solution
//Runtime: 95 ms
class Solution {
public:

    bool inDict(vector<string>&dict,string s)
    {
        if(find(dict.begin(),dict.end(), s) != dict.end())
            return 1;
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        int len = s.size();
        bool DP[len+1][len+1];

        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                DP[i][j] = 0;

        for(int l=1;l<=len;l++)
        {
            for(int i=0;i<len-l+1;i++)
            {
                int j = i+l-1;
                if(inDict(wordDict, s.substr(i,l)))
                    DP[i][j] = 1;
                else
                {
                    for(int k=i;k<j;k++)
                    {
                        if((DP[i][k] && DP[k+1][j] )|| (inDict(wordDict, s.substr(i,l+k-1)) && inDict(wordDict, s.substr(k+1, l-k))))
                        {
                            DP[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }

        return DP[0][len-1];
    }

};



//Optimal solution
//Runtime: 3 ms
class Solution {
public:

    bool inDict(vector<string>&dict,string s)
    {
        if(find(dict.begin(),dict.end(), s) != dict.end())
            return 1;
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        int len = s.size();
        bool DP[len+1];

        for(int i=0;i<=len;i++)
            DP[i] = 0;

        DP[0] = 1;
        for(int i=1;i<=len;i++)
        {
            for(int j=i-1;j>=0;j--)
                if(DP[j] && inDict(wordDict, s.substr(j,i-j)))
                {
                    DP[i] = 1;
                    break;
                }
        }

        return DP[len];
    }

};
