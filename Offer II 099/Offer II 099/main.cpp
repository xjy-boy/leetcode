#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp = vector<int>(grid[0].size(), 0);
        dp[0] = grid[0][0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++)
        {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++)
            {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6}
    };
    cout << s.minPathSum(grid) << endl;
}