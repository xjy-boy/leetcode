#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp;
        for (int i = 0; i < m; i++)
        {
            dp.emplace_back(n, 0);
        }
        int ans = 0;
        if (matrix[0][0] == '1')
        {
            dp[0][0] = 1;
            ans = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (matrix[0][i] == '1')
            {
                dp[0][i] = 1;
                ans = 1;
            }
        }
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                ans = max(ans,1);
            }

            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board =
    {
        {'1','0','1','1','1'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << s.maximalSquare(board) << endl;
}