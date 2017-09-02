class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    	unordered_map<int,int> ab;

    	vector<int>:: iterator it,jt;
    	for(it=A.begin();it!=A.end();it++)
    		for(jt=B.begin();jt!=B.end();jt++)
    			ab[*it + *jt]++;

    	int ans = 0;

    	for(it=C.begin();it!=C.end();it++)
    		for(jt=D.begin();jt!=D.end();jt++)
    		{
    			unordered_map<int,int>:: iterator abs;
    			abs = ab.find(0 - *it -*jt);
    			if(abs != ab.end())
    				ans += abs->second;
    		}

        return ans;
    }
};
