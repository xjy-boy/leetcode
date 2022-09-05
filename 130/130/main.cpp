#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (m <= 2 || n <= 2)
        {
            return;
        }

        vector<vector<bool>> connect;
        queue<pair<int, int>> searchQueue;
        for (int i = 0; i < m; i++)
        {
            if (i == 0 || i == m - 1)
            {
                connect.push_back(vector<bool>(n, true));
            }
            else
            {
                connect.push_back(vector<bool>(n, false));
                connect.back()[0] = true;
                connect.back()[n-1] = true;
            }

            if (board[i][0] == 'O')
            {
                searchQueue.push(pair<int, int>(i, 0));
            }

            if (board[i][n - 1] == 'O')
            {
                searchQueue.push(pair<int, int>(i, n - 1));
            }
            
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (board[0][i] == 'O')
            {
                searchQueue.push(pair<int, int>(0, i));
            }

            if (board[m-1][i] == 'O')
            {
                searchQueue.push(pair<int, int>(m-1, i));
            }
        }
        while (!searchQueue.empty())
        {
            int row = searchQueue.front().first;
            int column = searchQueue.front().second;
            searchQueue.pop();

            if (row != 0 && board[row - 1][column] == 'O'&& !connect[row - 1][column])
            {
                connect[row - 1][column] = true;
                searchQueue.push(pair<int, int>(row-1,column));
            }

            if (row != m-1 && board[row + 1][column] == 'O' && !connect[row + 1][column])
            {
                connect[row + 1][column] = true;
                searchQueue.push(pair<int, int>(row + 1, column));
            }

            if (column != 0 && board[row][column - 1] == 'O' && !connect[row][column - 1])
            {
                connect[row][column - 1] = true;
                searchQueue.push(pair<int, int>(row, column - 1));
            }

            if (column != n-1 && board[row][column + 1] == 'O' && !connect[row][column + 1])
            {
                connect[row][column + 1] = true;
                searchQueue.push(pair<int, int>(row, column + 1));
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!connect[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board =
        {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    s.solve(board);
}