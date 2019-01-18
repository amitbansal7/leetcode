//Runtime: 72 ms
class Solution {
public:
  int repeatedNTimes(vector<int>& A) {
    map<int, int> mp;
    int n = A.size() / 2;
    for (int a : A) {
      mp[a]++;
      if (mp[a] == n) {
        return a;
      }
    }
    return -1;
  }
};

//Runtime: 40 ms
class Solution {
public:
  int repeatedNTimes(vector<int>& A) {
    set<int> s;
    for (int a : A) {
      if (s.find(a) != s.end())
        return a;

      s.insert(a);
    }
    return -1;
  }
};

//Runtime: 40 ms
class Solution {
public:
  int repeatedNTimes(vector<int>& A) {
    for (int i = 0; i < A.size() - 2; i++) {
      if (A[i + 1] == A[i] || A[i] == A[i + 2]) {
        return A[i];
      }
    }
    return A[A.size() - 1];
  }
};