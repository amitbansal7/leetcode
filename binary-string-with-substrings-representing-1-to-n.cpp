// Runtime: 4 ms
// Memory Usage: 8.7 MB
class Solution {
public:

  string nToBinary(int n) {
    string s = "";
    while (n) {
      s = (to_string(n % 2)) + s;
      n /= 2;
    }
    return s;
  }

  bool queryString(string S, int N) {
    for (int i = N; i > N / 2; i--) {
      if (S.find(nToBinary(i)) == string::npos)
        return false;
    }
    return true;
  }
};