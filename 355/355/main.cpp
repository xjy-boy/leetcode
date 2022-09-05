#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


class Twitter {
private:
    vector<pair<int, int>> tweetList;
    vector<unordered_set<int>> followList;
public:
    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        int  t = userId - followList.size() + 1;
        for (int i = 0; i < t; i++)
        {
            followList.push_back(unordered_set<int>());
        }
        tweetList.emplace_back(userId,tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        int  t = userId - followList.size() + 1;
        for (int i = 0; i < t; i++)
        {
            followList.push_back(unordered_set<int>());
        }
        vector<int> ans;
        int index = tweetList.size() - 1;
        while (index >= 0 && ans.size() < 10)
        {
            if (tweetList[index].first == userId || followList[userId].count(tweetList[index].first))
            {
                ans.emplace_back(tweetList[index].second);
            }
            index -= 1;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        int t = followerId - followList.size() + 1;
        for (int i = 0; i < t; i++)
        {
            followList.push_back(unordered_set<int>());
        }
        followList[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        int t = followerId - followList.size() + 1;
        for (int i = 0; i < t; i++)
        {
            followList.push_back(unordered_set<int>());
        }
        followList[followerId].erase(followeeId);
    }
};
