//Runtime: 3 ms
class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	vector<string>res;
    	if(digits.empty()) return res;
    	vector<string> S = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    	res.push_back("");
    	for(int i=0;i<digits.length();i++)
    	{
    		int d = digits[i] - '0';
    		string can = S[d];
    		vector<string>t;

    		for(int j=0;j<can.length();j++)
    			for(int k=0;k<res.size();k++)
    				t.push_back(res[k]+can[j]);

    		res.swap(t);
    	}
    	return res;
    }
};
