class Leaderboard {
public:

  unordered_map<int, int> scores;
  set<pair<int, int> > pairs;

  Leaderboard() {

  }

  void addScore(int playerId, int score) {
    pairs.erase({scores[playerId], playerId});
    scores[playerId] += score;
    pairs.insert({scores[playerId], playerId});
  }

  int top(int K) {
    int res = 0;
    int i = 0;
    for (auto it = pairs.rbegin(); it != pairs.rend() && i < K; it++, i++) {
      res += it->first;
    }
    return res;
  }
  void reset(int playerId) {
    pairs.erase({scores[playerId], playerId});
    scores[playerId] = 0;
  }
};
