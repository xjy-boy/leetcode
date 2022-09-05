#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size(), 0);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            int pre = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    pre = max(pre, dp[j]);
                }
            }
            dp[i] = pre + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    cout << s.lengthOfLIS(nums) << endl;
}