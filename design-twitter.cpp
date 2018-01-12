//Runtime: 42 ms
class Twitter {
public:
	/** Initialize your data structure here. */

	unordered_map<int, set<int> > followers;
	unordered_map<int, priority_queue< pair<int, int>, vector<pair<int, int> > > >tweets;
	int ts;

	Twitter() {
		ts = 1;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		tweets[userId].push(make_pair(ts++, tweetId));
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		follow(userId, userId);
		priority_queue< pair<int, int>, vector<pair<int, int> > >pq;

		for (int user : followers[userId]) {
			priority_queue< pair<int, int>, vector<pair<int, int> > >tpq = tweets[user];
			for (int i = 0; i < 10, !tpq.empty(); i++) {
				pq.push(tpq.top());
				tpq.pop();
			}
		}
		vector<int> res;
		while (!pq.empty()) {
			if (res.size() == 10)
				break;
			auto t = pq.top();
			res.push_back(t.second);
			pq.pop();
		}

		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		followers[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followers.find(followerId) == followers.end())
			return;

		followers[followerId].erase(followeeId);
	}
};
