//Runtime: 128 ms
class Solution {
public:
  vector<int> sortedSquares(vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
      A[i] = pow(A[i], 2);
    }
    sort(A.begin(), A.end());
    return A;
  }
};


//Runtime: 80 ms
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());

        int l = 0, r = A.size()-1;
        for(int i=A.size()-1;i>=0;i--){
            if(abs(A[l]) > abs(A[r])){
                res[i] = pow(A[l++], 2);
            }else{
                res[i] = pow(A[r--], 2);
            }
        }

        return res;
    }
};