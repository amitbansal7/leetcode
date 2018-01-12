//Runtime: 17 ms

class Solution {
private:
    struct Comp {
        bool operator() (const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto a : words) {
            mp[a]++;
        }

        priority_queue<pair<string, int> , vector<pair<string, int> >, Comp > pq;

        for (auto a : mp) {
            pq.push(a);
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
