// Runtime: 12 ms
// Memory Usage: 10.3 MB
class Solution {
public:

  float slope(vector<vector<int> > &coordinates, int i, int j) {
    return (float)(coordinates[j][1] - coordinates[i][1]) / (float)(coordinates[j][0] - coordinates[i][0]);
  }

  bool checkStraightLine(vector<vector<int>>& coordinates) {
    float slp = slope(coordinates, 0, 1);

    for (int i = 1; i < coordinates.size() - 1; i++) {
      if (slp != slope(coordinates, i, i + 1)) {
        return false;
      }
    }
    return true;

  }
};