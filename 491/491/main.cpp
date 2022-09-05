#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return {};
        }
        vector<vector<int>> ans;
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>();
        bool flag = true;
        for (int i = 0; i < nums.size(); i++)
        {
            dp.push_back({});
            flag = true;
            for (int j = i-1; j >= 0; j--)
            {
                if (nums[i] >= nums[j])
                {
                    for (vector<int> pre : dp[j])
                    {
                        pre.emplace_back(nums[i]);
                        ans.emplace_back(pre.begin(), pre.end());
                        dp[i].emplace_back(pre.begin(), pre.end());
                    }
                }
                if (nums[i] == nums[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                dp[i].push_back({ nums[i] });
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 4,6,7,7 };
    s.findSubsequences(nums);
}