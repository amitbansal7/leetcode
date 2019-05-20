// Runtime: 32 ms
// Memory Usage: 13.2 MB
class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    set<string> st;
    for (string em : emails) {
      int i = 0;
      string s = "";
      while (i < em.size()) {
        if (em[i] == '.') i++;
        else if (em[i] == '+' || em[i] == '@') break;
        else s += em[i++];
      }
      while (em[i] != '@' && i < em.size()) i++;
      while (i < em.size()) s += em[i++];

      st.insert(s);
    }
    return st.size();
  }
};