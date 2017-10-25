//Runtime: 19 ms
class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0;
        int dn = 0;
        int lt = 0;
        int rt = 0;

        for(char c:moves)
        {
            if(c == 'U')
                up++;
            else if(c == 'D')
                dn++;
            else if(c == 'L')
                lt++;
            else if(c == 'R')
                rt++;
        }

        return (lt == rt && up == dn);
    }
};
