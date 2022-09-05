#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int dp[200][200];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < grid.size(); i++)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            for (int j = 1; j < grid[i].size(); j++)
            {
                dp[i][j] =  grid[i][j] + max(dp[i-1][j], dp[i][j - 1]);
            }
        }
        return dp[grid.size() - 1][grid[0].size()-1];
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution s;
    cout << s.maxValue(grid) << endl;
}