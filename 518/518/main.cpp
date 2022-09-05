#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> dp;
    vector<bool> visit;
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
        {
            return 0;
        }
        dp = vector<int>(amount + 1, 0);
        //visit = vector<bool>(amount + 1, false);
        dp[0] = 1;
        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution s;
    vector<int> coins = { 7 };
    cout << s.change(0, coins) << endl;
}