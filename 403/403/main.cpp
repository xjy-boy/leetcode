#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class Solution {
public:
    /*
    vector<unordered_set<int>> dp;
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < stones.size(); i++)
        {
            indexMap[stones[i]] = i;
        }
        dp = vector<unordered_set<int>>(stones.size());
        dp[0].insert(1);
        int next = 0;
        int nextIndex;
        for (int i = 0; i < dp.size(); i++)
        {
            for (int it : dp[i])
            {
                next = stones[i] + it;
                if (indexMap.count(next))
                {
                    nextIndex = indexMap[next];
                    if (nextIndex == stones.size() - 1)
                    {
                        return true;
                    }
                    if (it != 1)
                    {
                        dp[nextIndex].insert(it - 1);
                    }
                    dp[nextIndex].insert(it);
                    dp[nextIndex].insert(it + 1);
                }
            }
        }
        return false;
    }*/

    vector<unordered_map<int, bool>> memory;
    unordered_map<int, int> indexMap;
    bool canCross(vector<int>& stones) {
        memory = vector<unordered_map<int, bool>>(stones.size() - 1);
        for (int i = 0; i < stones.size(); i++)
        {
            indexMap[stones[i]] = i;
        }
        return dfs(stones,0, 0);
    }

    bool dfs(vector<int> &stones,int index, int lastDis) {
        if (index == stones.size() - 1)
        {
            return true;
        }
        else if (memory[index].count(lastDis))
        {
            return memory[index][lastDis];
        }
        else
        {
            int next = 0;
            int nextIndex = 0;
            int dis = 0;
            for (int i = -1; i <= 1; i++)
            {
                dis = lastDis + i;
                if (dis > 0)
                {
                    next = stones[index] + dis;
                    if (indexMap.count(next))
                    {
                        nextIndex = indexMap[next];
                        if (dfs(stones, nextIndex, dis))
                        {
                            return true;
                        }
                    }
                }
            }
            memory[index][lastDis] = false;
            return false;
        }
    }
};