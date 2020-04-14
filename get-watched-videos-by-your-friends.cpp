// Runtime: 124 ms
// Memory Usage: 31.5 MB
class Solution {
public:

  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    map<string, int> viewCount;
    vector<int> vis(friends.size(), 0);

    queue<int >q;
    q.push(id);
    int d = 0;
    vis[id] = 1;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int t = q.front();
        q.pop();
        if (d == level) {
          for (string a : watchedVideos[t]) {
            viewCount[a]++;
          }
        }

        for (int f : friends[t]) {
          if (!vis[f]) {
            vis[f] = 1;
            q.push(f);
          }
        }
      }
      if (d >= level) {
        break;
      }
      d++;
    }

    vector<pair<string, int> >countVec(viewCount.begin(), viewCount.end());
    sort(countVec.begin(), countVec.end(), [](pair<string, int> &a, pair<string, int> &b) {
      return a.second == b.second ? a.first < b.first : a.second < b.second;
    });
    vector<string> res;
    for (auto a : countVec) {
      res.push_back(a.first);
    }
    return res;
  }
};