#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = vector<int>(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j < amount + 1; j++) {
                if (dp[j - coins[i]] == -1) {
                    continue;
                }
                else if(dp[j] == -1){
                    dp[j] = dp[j - coins[i]] + 1;
                }
                else {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution solution = Solution();
    vector<int> coins = { 2,3,5 };
    int amount = 11;
    cout << solution.coinChange(coins, amount) << endl;

}