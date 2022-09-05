#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    vector<int> dx = { -1,-1,-1,0,0,1,1,1 };
    vector<int> dy = { -1,0,1,-1,1,-1,0,1 };
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                for (int k = 0; k < 8; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] & 1))
                    {
                        sum += 1;
                    }
                }
                if (board[i][j] == 1)
                {
                    if (sum == 2 || sum == 3)
                    {
                        board[i][j] += 2;
                    }
                }
                else
                {
                    if (sum == 3)
                    {
                        board[i][j] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};