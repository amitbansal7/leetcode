//Runtime: 3 ms
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>keyboard;
        string first = "qwertyuiop"; keyboard.push_back(first);
        string second = "asdfghjkl"; keyboard.push_back(second);
        string third = "zxcvbnm";    keyboard.push_back(third);

        vector<string>res;
        int findc;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<3;j++)
            {
                findc = 1;
                for(char a:words[i])
                    if(keyboard[j].find(tolower(a)) == string::npos)
                    {
                        findc = 0;
                        break;
                    }

                if(findc)
                    break;
            }

            if(findc)
                res.push_back(words[i]);
        }
        return res;
    }
};
