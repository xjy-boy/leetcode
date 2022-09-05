#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[2] = { 0 };
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i % 2] = max(dp[i % 2] + nums[i], dp[1 - i % 2]);
        }
        return max(dp[0], dp[1]);
    }
};

int main()
{
    vector<int> nums = { 100,2,3,100,1 };
    Solution s;
    cout << s.rob(nums) << endl;
}