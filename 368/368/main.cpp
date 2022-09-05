#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp = vector<int>(nums.size(), 0);
        vector<int> pre = vector<int>(nums.size(), -1);
        int maxSize = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[j] > dp[i])
                {
                    dp[i] = dp[j];
                    pre[i] = j;
                }
            }
            dp[i] += 1;
            maxSize = max(maxSize, dp[i]);
        }

        vector<int> ans;
        int index = nums.size() - 1;
        while (index >= 0)
        {
            if (dp[index] == maxSize)
            {
                while (pre[index] >= 0)
                {
                    ans.emplace_back(nums[index]);
                    index = pre[index];
                }
                ans.emplace_back(nums[index]);
                break;
            }
            index -= 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4,5,6,7,8};
    s.largestDivisibleSubset(nums);
}