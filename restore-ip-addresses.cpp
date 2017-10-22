//Runtime: 3 ms
//Learned from discuss section
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ans;

        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    for(int l=1;l<=3;l++)
                    {
                        if(i+j+k+l == s.size())
                        {
                            int a = stoi(s.substr(0,i));
                            int b = stoi(s.substr(i,j));
                            int c = stoi(s.substr(i+j,k));
                            int d = stoi(s.substr(i+j+k,l));

                            if(a<=255 && b<=255 && c<=255 && d<=255)
                              if((ans = to_string(a) + '.' + to_string(b)+'.'+to_string(c)+'.'+to_string(d)).size()==s.size()+3)
                                res.push_back(ans);
                        }
                    }
                }
            }
        }
        return res;
    }
};
