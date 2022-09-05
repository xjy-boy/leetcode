#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int dp[3] = { 0 };
        int nowMin[3] = { 0 };
        for (int i = 0; i < costs.size(); i++)
        {
            nowMin[0] = costs[i][0] + min(dp[1], dp[2]);
            nowMin[1] = costs[i][1] + min(dp[0], dp[2]);
            nowMin[2] = costs[i][2] + min(dp[0], dp[1]);
            dp[0] = nowMin[0];
            dp[1] = nowMin[1];
            dp[2] = nowMin[2];
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};

int main()
{
    Solution s;
    vector<vector<int>> costs = {{3, 5, 3}, {6, 17, 6}, {7, 13, 18}, {9, 10, 18}};
    cout << s.minCost(costs) << endl;
}