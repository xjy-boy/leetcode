#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dir =
    {
        {-1,0},
        {1,0},
        {0,1},
        {0,-1}
    };
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        vector<vector<vector<int>>> dp;
        for (int i = 0; i < 2; i++)
        {
            dp.push_back(vector<vector<int>>());
            for (int j = 0; j < m; j++)
            {
                dp[i].emplace_back(n, 0);
            }
        }
        int move = 0;
        dp[0][startRow][startColumn] = 1;
        int nextRow = 0;
        int nextColumn = 0;
        int index = 0;
        while (move < maxMove)
        {
            index = move % 2;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j< n; j++)
                {
                    dp[1 - index][i][j] = 0;
                }
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dp[index][i][j] > 0)
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            nextRow = i + dir[k][0];
                            nextColumn = j + dir[k][1];
                            if (nextRow >= 0 && nextRow < m &&
                                nextColumn >= 0 && nextColumn < n)
                            {
                                dp[1 - index][nextRow][nextColumn] =
                                    (dp[1 - index][nextRow][nextColumn] +
                                        dp[index][i][j]) % mod;
                            }
                            else
                            {
                                ans = (ans + dp[index][i][j]) % mod;
                            }
                        }
                    }
                }
            }
            move += 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.findPaths(1, 3, 3, 0, 1) << endl;
}