//Runtime: 291 ms
class Solution {
public:
	int change(string &a, string &b) {
		int t = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i])
				t++;
		}
		return t;
	}

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_map<string, int> stringToId;
		unordered_map<int, string> IdToString;
		unordered_map<int, vector<int> >graph;
		int id = 1;
		wordList.push_back(beginWord);

		for (string s : wordList) {
			if (stringToId.find(s) == stringToId.end()) {
				stringToId[s] = id;
				IdToString[id++] = s;
			}
		}

		for (int i = 0; i < wordList.size(); i++) {
			for (int j = i + 1; j < wordList.size(); j++) {
				if (change(wordList[i], wordList[j]) == 1) {
					int x = stringToId[wordList[j]];
					int y = stringToId[wordList[i]];
					graph[x].push_back(y);
					graph[y].push_back(x);
				}
			}
		}

		queue<int> Q;
		vector<int>dist(id + 2);
		unordered_set<int> vis;
		int src = stringToId[beginWord];
		int dest = stringToId[endWord];
		Q.push(src);
		vis.insert(src);
		dist[src] = 1;
		while (!Q.empty()) {
			int t = Q.front();
			Q.pop();
			for (int a : graph[t]) {
				if (vis.find(a) == vis.end()) {
					Q.push(a);
					vis.insert(a);
					dist[a] = dist[t] + 1;
				}
				if (a == dest)
					return dist[dest];
			}
		}
		if (vis.find(dest) == vis.end())
			return 0;

		return dist[dest];
	}
};
