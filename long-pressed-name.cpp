// Runtime: 0 ms
// Memory Usage: 8.5 MB
class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    int i = 0;
    int j = 0;

    while (i < name.size()) {
      if (name[i] == typed[j]) {
        i++; j++;
      }
      else if (i > 0 && name[i - 1] == typed[j]) j++;
      else return false;
    }

    return i == name.size();
  }
};