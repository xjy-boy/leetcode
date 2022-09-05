#include<iostream>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[9] = { 0 };
        dp[0] = 10;
        dp[1] = 90;
        for (int i = 2; i < n; i++)
        {
            dp[i] = dp[i - 1] * (10 - i);
        }
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return 10;
        }
        else
        {
            int ans = dp[0];
            for (int i = 1; i < n; i++)
            {
                ans += dp[i] - dp[i] / 10;
            }
            return ans;
        }
    }
};

int main()
{
    Solution s;
    cout << s.countNumbersWithUniqueDigits(3) << endl;
}