#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        vector<int> dp = vector<int>(sum / 2 + 1);
        //±ß½çÌõ¼þ
        for (int i = 0; i < sum / 2 + 1; i++)
        {
            if (i >= nums[0])
            {
                dp[i] = nums[0];
            }
            else
            {
                dp[i] = 0;
            }
        }
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = sum / 2; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[sum / 2] == sum / 2;
    }
};

int main()
{
    vector<int> nums = { 2,2,3,5 };
    Solution s;
    cout << s.canPartition(nums) << endl;
}
