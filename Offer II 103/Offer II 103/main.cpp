#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = vector<int>(amount + 1, -1);
        dp[0] = 0;
        for (int coin : coins)
        {
            for (int i = coin; i < amount + 1; i++)
            {
                if (dp[i - coin] >= 0)
                {
                    if (dp[i] < 0 || dp[i - coin] + 1 < dp[i])
                    {
                        dp[i] = dp[i - coin] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1,2,5};
    cout << s.coinChange(coins, 11) << endl;
}