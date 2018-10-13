#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iterator>
#include <numeric>
#include <bitset>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Twitter
{
    vector<pair<int, int>> tweets;
    unordered_map<int, set<int>> list;

  public:
    /** Initialize your data structure here. */
    Twitter()
    {
    }

    /** Compose a new tweets. */
    void postTweet(int userId, int tweetId)
    {
        tweets.push_back({userId, tweetId});
    }

    /** Retrieve the 10 most recent tweets ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        auto &followed = list[userId];
        for (int i = tweets.size() - 1, size = 0; i >= 0 && size < 10; --i)
            if (followed.count(tweets[i].first) || tweets[i].first == userId)
            {
                ans.push_back(tweets[i].second);
                ++size;
            }
        return ans;
    }
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void
    follow(int followerId, int followeeId)
    {
        list[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        list[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

/*int timestamp = 0;

class Twitter
{
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, set<int>> follows;

  public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        auto tt = make_pair(timestamp++, tweetId);
        posts[userId].push_back(tt);
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        map<int, pair<int, int>> pq;
        unordered_map<int, int> tokens;
        follows[userId].insert(userId);
        for (auto x : follows[userId])
        {
            int k = posts[x].size() - tokens[x] - 1;
            if (k < 0)
                continue;
            pq[posts[x][k].first] = make_pair(posts[x][k].second, x);
            ++tokens[x];
        }

        for (int i = 0; i < 10 && pq.size() > 0; ++i)
        {
            auto it = pq.end();
            --it;
            pair<int, int> tmp = it->second;
            int x = tmp.second, p = tmp.first;
            ans.push_back(p);
            pq.erase(it);
            int k = posts[x].size() - tokens[x] - 1;
            if (k < 0)
                continue;
            pq[posts[x][k].first] = make_pair(posts[x][k].second, x);
            ++tokens[x];
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].erase(followeeId);
    }
};*/