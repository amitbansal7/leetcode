//Runtime: 29 ms
class Solution {
public:
    int nc;
    int sp;
    void solve(vector<vector<int> > &image, int i, int j) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size())
            return;
        if (image[i][j] == sp) {
            image[i][j] = nc;
            solve(image, i + 1, j);
            solve(image, i - 1, j);
            solve(image, i, j + 1);
            solve(image, i, j - 1);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.size() < 1)
            return image;
        if (image[0].size() < 1)
            return image;
        nc = newColor;
        sp = image[sr][sc];
        if (nc != sp)
            solve(image, sr, sc);
        return image;
    }
};
