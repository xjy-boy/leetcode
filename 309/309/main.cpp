#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dpSell = vector<int>(prices.size(),0);
        vector<int> dpBuy = vector<int>(prices.size(), 0);
        vector<int> dpCool = vector<int>(prices.size(), 0);
        dpSell[0] = 0;
        dpBuy[0] = -prices[0];
        dpCool[0] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dpCool[i] = max(dpSell[i - 1], dpCool[i - 1]);
            dpBuy[i] = max(dpBuy[i - 1], dpCool[i - 1] - prices[i]);
            dpSell[i] = max(prices[i] + dpBuy[i - 1], dpSell[i - 1]);
        }
        return max(dpSell.back(), dpCool.back());
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,0,2 };
    cout << s.maxProfit(nums) << endl;
}