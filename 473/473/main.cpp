#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int length = 0;
        for (int num : matchsticks)
        {
            length += num;
        }
        if (length % 4 != 0)
        {
            return false;
        }
        length = length / 4;
        for (int num : matchsticks)
        {
            if (num > length)
            {
                return false;
            }
        }
        vector<int> dp = vector<int>(pow(2, matchsticks.size()), -1);
        int pre = 0;
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 0; j < matchsticks.size(); j++)
            {
                if (i & (1 << j))
                {
                    pre = i - (1 << j);
                    if (dp[pre] >= 0)
                    {
                        int next = dp[pre] + matchsticks[j];
                        if (next <= length)
                        {
                            dp[i] = next % length;
                            break;
                        }
                    }
                }
            }
        }
        return dp.back() == 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    s.makesquare(nums);
}