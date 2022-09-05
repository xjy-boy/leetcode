#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp;
        int m = dungeon.size();
        int n = dungeon[0].size();
        for (int i = 0; i < m; i++)
        {
            dp.emplace_back(n, 0);
        }
        dp[m - 1][n - 1] = max(-dungeon[m - 1][n - 1] + 1,1);
        for (int i = n - 2; i >= 0; i--)
        {
            dp[m - 1][i] = max(dp[m - 1][i + 1] - dungeon[m - 1][i],1);
            
        }

        for (int i = m - 2; i >= 0; i--)
        {
            dp[i][n - 1] = max(dp[i + 1][n - 1]- dungeon[i][n - 1], 1);
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j],1);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    vector<vector<int>> d = {
        {-2,-3,3},
        {-5,-10,1},
        {10,30,-5}
    };
    Solution s;
    cout << s.calculateMinimumHP(d) << endl;
}