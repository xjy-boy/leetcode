#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        double p = 1.0 / 6.0;
        vector<double> dp = vector<double>(n * 6 + 1, 0);
        dp[1] = p;
        dp[2] = p;
        dp[3] = p;
        dp[4] = p;
        dp[5] = p;
        dp[6] = p;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 6*i; j >= i; j--)
            {
                dp[j] = 0;
                for (int k = 1; k <= 6; k++)
                {
                    if (j - k <= 0)
                    {
                        continue;
                    }
                    dp[j] += p * dp[j - k];
                }
            }
            for (int j = 0; j < i; j++)
            {
                dp[j] = 0;
            }
        }
        vector<double> ans;
        for (int i = n; i <= n * 6; i++)
        {
            ans.emplace_back(dp[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.dicesProbability(3);
}