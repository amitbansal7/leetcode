//Runtime: 6 ms
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        set<string> res;

        for(string s:words){
            string t = "";
            for(char c:s){
                t += morse[c-'a'];
            }

            res.insert(t);
        }
        return res.size();
    }
};