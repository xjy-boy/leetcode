#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    const vector<vector<int>> dir = {
        {-1,-1},
        {1,-1},
        {-1,1},
        {1,1},
        {0,-1},
        {-1,0},
        {0,1},
        {1,0},
    };
public:
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        int nextRow = 0;
        int nextColumn = 0;
        int num = 0;
        for (int i = 0; i < 8; i++)
        {
            nextRow = x + dir[i][0];
            nextColumn = y + dir[i][1];
            if (nextRow >= 0 && nextRow < board.size() &&
                nextColumn >= 0 && nextColumn < board[0].size())
            {
                if (board[nextRow][nextColumn] == 'M')
                {
                    num += 1;
                }
            }
        }
        if (num == 0)
        {
            board[x][y] = 'B';
            for (int i = 0; i < 8; i++)
            {
                nextRow = x + dir[i][0];
                nextColumn = y + dir[i][1];
                if (nextRow >= 0 && nextRow < board.size() &&
                    nextColumn >= 0 && nextColumn < board[0].size() &&
                    board[nextRow][nextColumn] == 'E')
                {
                    dfs(board, nextRow,nextColumn);
                }
            }
        }
        else
        {
            board[x][y] = '0' + num;
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
        }
        else if (board[click[0]][click[1]] == 'E')
        {
            dfs(board, click[0], click[1]);
        }
        return board;
    }
};