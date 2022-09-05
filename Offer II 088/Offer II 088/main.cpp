#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2] = { 0,0 };
        for (int i = cost.size() - 1; i >= 0; i--)
        {
            dp[i % 2] = cost[i] + min(dp[0], dp[1]);
        }
        return min(dp[0], dp[1]);
    }
};

int main()
{
    vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };
    Solution s;
    cout << s.minCostClimbingStairs(cost) << endl;
}