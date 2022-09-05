#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    //dp[i][j]代表左端选到i,右端选到j时，当前玩家能取得的最大分差
    vector<vector<int>> dp;
    vector<vector<bool>> visit;
public:
    bool PredictTheWinner(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            dp.emplace_back(nums.size(), 0);
            visit.emplace_back(nums.size(), false);
        }
        return dfs(nums, 0, nums.size() - 1) >= 0;
    }

    int dfs(vector<int>& nums, int left, int right) {
        if (visit[left][right])
        {
            return dp[left][right];
        }
        else if (left == right)
        {
            return nums[left];
        }

        dp[left][right] = max(nums[left] - dfs(nums, left + 1, right),
            nums[right] - dfs(nums, left, right - 1));

        visit[left][right] = true;
        return dp[left][right];
    }
};