#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int dp[2] = { 0 };
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i % 2] = max(dp[i % 2] + nums[i], dp[1 - i % 2]);
        }
        int result = max(dp[0], dp[1]);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            dp[i % 2] = max(dp[i % 2] + nums[i], dp[1 - i % 2]);
        }
        return max(result,max(dp[0], dp[1]));
    }
};

int main()
{
    Solution solution;
    vector<int> nums{ 1,100,1,1,100 };
    cout << solution.rob(nums) << endl;
}