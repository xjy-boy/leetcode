#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //dp[i][j]表示在j天之前完成了i笔交易时的利润
        vector<vector<int>> dp;
        for (int i = 0; i <= k;i++)
        {
            dp.emplace_back(prices.size() + 1, 0);
        }
        int index = 0;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j < prices.size(); j++)
            {
                index = j + 1;
                dp[i][index] = max(dp[i][j], dp[i - 1][index]);
                for (int k = 0; k < j; k++)
                {
                    if (prices[k] < prices[j])
                    {
                        dp[i][index] = max(dp[i][index], dp[i - 1][k] + prices[j] - prices[k]);
                    }
                }
            }
        }
        
        return dp.back().back();
    }
};


int main()
{
    vector<int> prices = { 6,1,3,2,4,7 };

    Solution s;
    cout << s.maxProfit(2,prices) << endl;
}