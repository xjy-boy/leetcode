#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp = vector<unordered_map<int, int>>(2);
        dp[0][0] = 1;
        int index = 0;
        int next1 = 0;
        int next2 = 0;
        for (int num : nums)
        {
            index = (index + 1) % 2;
            dp[index].clear();
            for (auto it = dp[1 - index].begin(); it != dp[1 - index].end(); it++)
            {
                next1 = it->first + num;
                next2 = it->first - num;
                if (dp[index].count(next1))
                {
                    dp[index][next1] = dp[index][next1] + it->second;
                }
                else
                {
                    dp[index][next1] = it->second;
                }

                if (dp[index].count(next2))
                {
                    dp[index][next2] = dp[index][next2] + it->second;
                }
                else
                {
                    dp[index][next2] = it->second;
                }
            }
        }

        if (dp[index].count(target))
        {
            return dp[index][target];
        }
        else
        {
            return 0;
        }
    }
};