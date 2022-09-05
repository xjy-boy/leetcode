#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans  = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int t = prices[i] - prices[i-1];
            if (t > 0)
            {
                ans += t;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> p = { 7,1,5,3,6,4 };
    cout << s.maxProfit(p) << endl;
}

