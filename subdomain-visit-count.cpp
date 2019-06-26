//Runtime: 20 ms
//Memory Usage: 13.3 MB
class Solution {
public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    map<string, int> mp;
    for (string d : cpdomains) {
      int idx = d.find(' ');
      int count = stoi(d.substr(0, idx));
      string str = d.substr(idx + 1);
      mp[str] += count;
      for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
          mp[str.substr(i + 1)] += count;
        }
      }
    }
    vector<string> res;
    for (auto a : mp) {
      res.push_back(to_string(a.second) + " " + a.first);
    }

    return res;
  }
};