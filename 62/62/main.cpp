#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] > 0)
        {
            return 0;
        }
        vector<int> dp = vector<int>(obstacleGrid[0].size(), 0);
        for (int i = 0; i < dp.size(); i++)
        {
            if (obstacleGrid[0][i] > 0)
            {
                break;
            }
            dp[i] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            if (obstacleGrid[i][0] > 0)
            {
                dp[0] = 0;
            }
            for (int j = 1; j < dp.size(); j++)
            {
                if (obstacleGrid[i][j] > 0)
                {
                    dp[j] = 0;
                }
                else
                {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};

int main()
{
    vector<vector<int>> o = {
        {0, 1, 0, 0, 0}, 
        {1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0}
    };
    Solution s;
    cout << s.uniquePathsWithObstacles(o) << endl;
}