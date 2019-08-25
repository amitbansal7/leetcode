// Runtime: 28 ms
// Memory Usage: 14.5 MB
class Solution {
public:

  int freq(string &w) {
    vector<int> mp(26, 0);
    for (char a : w) {
      mp[a - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (mp[i] > 0) {
        return mp[i];
      }
    }
    return -1;
  }

  vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> freqs;
    for (string w : words) {
      freqs.push_back(freq(w));
    }
    sort(freqs.begin(), freqs.end());
    vector<int> res;
    for (string s : queries) {
      res.push_back(freqs.end() - upper_bound(freqs.begin(), freqs.end(), freq(s)));
    }
    return res;
  }
};