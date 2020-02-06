#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;


class Twitter {
public:
	list <pair<int, int>> l;
	unordered_map<int, unordered_map<int, bool>> f;

	/** Initialize your data structure here. */
	Twitter() {
		l.clear();
		f.clear();
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		l.push_front(make_pair(userId, tweetId));
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<int> ans;
		for (auto it : l) {
			if (it.first == userId || f[userId][it.first] == true) {
				ans.push_back(it.second);
			}
			if (ans.size() >= 10) break;
		}
		return ans;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		f[followerId][followeeId] = true;

	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		//for (auto it : f[followerId]) {
		//	if (it == followeeId) f.erase(it);
		//}

		//f[followerId].erase(followeeId);
		f[followerId][followeeId] = false;
	}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */