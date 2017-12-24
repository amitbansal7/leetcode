//Runtime: 509 ms
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> end;
        set<string> vis;

        for (string s : deadends)
            end.insert(s);

        if (end.find("0000") != end.end() || end.find(target) != end.end())
            return -1;

        vis.insert("0000");
        queue<pair<string, int> > Q;
        Q.push(make_pair("0000", 0));
        while (!Q.empty()) {
            pair<string, int> t = Q.front();
            Q.pop();
            string str = t.first;
            int depth = t.second;
            if (str == target)
                return depth;

            for (int i = 0; i < 4; i++) {
                for (int d = -1; d <= 1; d += 2) {
                    int num = ((str[i] - '0') + d + 10) % 10;
                    string naya = str.substr(0, i) + to_string(num) + str.substr(i + 1);
                    if (end.find(naya) == end.end() && vis.find(naya) == vis.end()) {
                        Q.push(make_pair(naya, depth + 1));
                        vis.insert(naya);
                    }
                }
            }
        }

        return -1;

    }
};
