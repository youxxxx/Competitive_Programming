#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#define MINUTE 60
#define HOUR 3600
#define DAY 86400

using namespace std;

class TweetCounts {
public:
	map<string, set<int>> *dlist;

	TweetCounts() {
		dlist = new map<string, set<int>>;

		dlist->clear();
	}

	~TweetCounts() {
		delete dlist;
	}

	void recordTweet(string tweetName, int time) {
		map<string, set<int>>::iterator ret;

		ret = (*dlist).find(tweetName);

		if (ret == (*dlist).end()) {
			set<int> newset;

			newset.insert(time);

			(*dlist)[tweetName] = newset;
		}

		else {
			ret->second.insert(time);
		}
	}

	vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {

		int base;

		if (freq == "minute") {
			base = MINUTE;
		}

		else if (freq=="hour") {
			base = HOUR;
		}

		else {
			base = DAY;
		}

		map<string, set<int>>::iterator ret;
		set<int>::iterator lb, ub;

		vector<int> rvalue;

		ret = (*dlist).find(tweetName);

		if (ret == (*dlist).end()) {
			return rvalue;
		}

		lb = ret->second.lower_bound(startTime);
		ub = ret->second.upper_bound(endTime);

		int q = -1;

		for (set<int>::iterator it = lb; it != ub; it++) {
			int next;
			next = (*it - startTime) / base;
			if (next != q) {
				for (int i = q + 1; i < next; i++) {
					rvalue.push_back(0);
				}
				rvalue.push_back(1);
				q = next;
			}

			else {
				rvalue[rvalue.size() - 1]++;
			}
		}

		for (int i = q + 1; i <= (endTime - startTime) / base; i++) {
			rvalue.push_back(0);
		}

		/*
		if (rvalue.empty()) {
			rvalue.push_back(0);
		}
		*/

		return rvalue;
	}
};

int main()
{
	TweetCounts tweetCounts;
	tweetCounts.recordTweet("tweet3", 0);
	tweetCounts.recordTweet("tweet3", 60);
	tweetCounts.recordTweet("tweet3", 10);                             // All tweets correspond to "tweet3" with recorded times at 0, 10 and 60.
	tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2]. The frequency is per minute (60 seconds), so there is one interval of time: 1) [0, 60> - > 2 tweets.
	tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2, 1]. The frequency is per minute (60 seconds), so there are two intervals of time: 1) [0, 60> - > 2 tweets, and 2) [60,61> - > 1 tweet.
	tweetCounts.recordTweet("tweet3", 120);                            // All tweets correspond to "tweet3" with recorded times at 0, 10, 60 and 120.
	tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4]. The frequency is per hour (3600 seconds), so there is one interval of time: 1) [0, 211> - > 4 tweets.

	return 0;
}