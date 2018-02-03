//Runtime: 6 ms
class Solution {
public:
    
    bool isnum(int n){
        int t = n;
        while(t){
           int w = t%10;
            t /=10;
           if(!w ||n%w!=0){
               return 0;
           } 
        }
        return 1;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;   
        for(int i=left;i<=right;i++){
            if(isnum(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};
