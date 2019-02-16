// Runtime: 16 ms
// Memory Usage: 11 MB
class Solution {
public:

  map<char, char> parent;
  map<char, char> rank;

  char find(char a) {
    if (parent[a] != a) {
      parent[a] = find(parent[a]);
    }
    return parent[a];
  }

  void merge(char a, char b) {
    if (rank[a] > rank[b]) {
      parent[find(a)] = find(b);
    } else {
      parent[find(b)] = find(a);
    }
    if (rank[a] == rank[b]) {
      rank[b]++;
    }
  }

  void init(char a) {
    if (parent.find(a) == parent.end()) {
      parent[a] = a;
      rank[a] = 0;
    }
  }

  bool equationsPossible(vector<string>& equations) {

    vector<pair<char, char> > check;

    for (string s : equations) {
      char a = s[0];
      char b = s[3];
      init(a);
      init(b);

      if (s[1] == '=') {
        merge(a, b);
      } else {
        check.push_back(make_pair(a, b));
      }
    }

    for (auto p : check) {
      if (find(p.first) == find(p.second)) {
        return false;
      }
    }

    return true;

  }
};