// Runtime: 16 ms
// Memory Usage: 7.3 MB
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    vector<int> h1(26, 0);
    vector<int> h2(26, 0);
    if (s2.size() < s1.size()) {
      return false;
    }
    for (char a : s1) {
      h1[a - 'a']++;
    }
    for (int i = 0; i < s1.size(); i++) {
      h2[s2[i] - 'a']++;
    }
    if (h1 == h2) {
      return true;
    }
    for (int i = s1.size(); i < s2.size(); i++) {
      h2[s2[i - s1.size()] - 'a']--;
      h2[s2[i] - 'a']++;
      if (h1 == h2) {
        return true;
      }
    }
    return false;
  }
};