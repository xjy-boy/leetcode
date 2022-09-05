#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'X')
                {
                    ans += 1;
                    if (i != 0 && board[i - 1][j] == 'X')
                    {
                        ans -= 1;
                    }
                    else if (j != 0 && board[i][j - 1] == 'X')
                    {
                        ans -= 1;
                    }
                }
            }
        }
        return ans;
    }
};