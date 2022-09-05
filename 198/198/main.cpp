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
        int dp1 = nums[0];
        int dp2 = nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            int now = dp1 + nums[i];
            dp1 = max(dp1, dp2);
            dp2 = now;
        }
        return max(dp1, dp2);
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,7,9,3,1 };
    cout << s.rob(nums) << endl;
}