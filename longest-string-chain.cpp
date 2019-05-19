// Runtime: 128 ms
// Memory Usage: 48.1 MB
class Solution {
public:

  vector<string> allPredecessors(string word) {
    vector<string> allP;
    for (int i = 0; i < word.size(); i++) {
      allP.push_back(word.substr(0, i) + word.substr(i + 1, word.size() - i - 1));
    }
    return allP;
  }

  int longestStrChain(vector<string>& words) {
    vector<vector<string> > wordsByLevel(17, vector<string>());
    int maxLen = 0;
    for (string w : words) {
      wordsByLevel[w.size()].push_back(w);
      maxLen = max(maxLen, (int)w.size());
    }
    unordered_map<string, int> dp;
    for (string s : words) {
      dp[s] = 1;
    }

    int res = 1;
    for (int len = 2; len <= maxLen; len++) {
      for (string word : wordsByLevel[len]) {
        vector<string> allP = allPredecessors(word);
        for (string w : allP) {
          dp[word] = max(dp[word], dp.find(w) == dp.end() ? 0 : dp[w] + 1);
        }
        res = max(dp[word], res);
      }
    }

    return res;
  }
};