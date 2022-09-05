#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp1 = vector<int>(prices.size(), 0);
        vector<int> dp2 = vector<int>(prices.size(), 0);
        int minValue = prices[0];
        int maxValue = prices.back();
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minValue)
            {
                minValue = prices[i];
                dp1[i] = dp1[i - 1];
            }
            else
            {
                dp1[i] = max(dp1[i - 1], prices[i] - minValue);
            }
            int index = prices.size() - i - 1;
            if (prices[index] > maxValue)
            {
                dp2[index] = dp2[index + 1];
                maxValue = prices[index];
            }
            else
            {
                dp2[index] = max(dp2[index + 1], maxValue - prices[index]);
            }
        }

        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            ans = max(ans, dp1[i] + dp2[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> p = { 7,6,4,3,1 };
    cout << s.maxProfit(p) << endl;
}