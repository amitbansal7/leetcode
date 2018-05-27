//Runtime: 9 ms
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), 0);
        vis[0] = 1;
        queue<int> Q;
        Q.push(0);

        while (!Q.empty()) {
            int t = Q.front();
            Q.pop();

            for (int a : rooms[t]) {
                if (!vis[a]) {
                    vis[a] = 1;
                    Q.push(a);
                }
            }
        }

        for (bool a : vis) {
            if (!a) return 0;
        }
        return 1;
    }
};