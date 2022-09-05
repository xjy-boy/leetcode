#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
    struct searchNode
    {
        int row;
        int column;
        int grid;
        vector<char> num;
        searchNode(int _row, int _column)
        {
            row = _row;
            column = _column;
            grid = (row / 3) * 3 + column / 3;
        }

        bool operator <(const searchNode &y) const
        {
            return num.size() < y.num.size();
        }
    };
private:
    bool  rows[9][9];
    bool  columns[9][9];
    bool  grids[9][9];
    vector<searchNode> searchQueue;
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, false, sizeof(rows));
        memset(columns, false, sizeof(columns));
        memset(grids, false, sizeof(grids));
        searchQueue.clear();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                rows[i][board[i][j]-'1'] = true; 
                columns[j][board[i][j] - '1'] = true;
                grids[(i / 3) * 3 + j / 3][board[i][j]-'1'] = true;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    continue;
                }
                searchQueue.emplace_back(searchNode(i, j));
                for (char k = '1'; k <= '9'; k++)
                {
                    if (!rows[i][k - '1'] && !columns[j][k - '1'] && !grids[searchQueue.back().grid][k - '1'])
                    {
                        searchQueue.back().num.emplace_back(k);
                    }
                }
            }
        }

        sort(searchQueue.begin(), searchQueue.end());
        search(0, board);
    }

    bool search(int index, vector<vector<char>>& board)
    {
        if (index == searchQueue.size())
        {
            return true;
        }
        for (char n : searchQueue[index].num)
        {
            if (!rows[searchQueue[index].row][n - '1'] && !columns[searchQueue[index].column][n - '1'] && !grids[searchQueue[index].grid][n - '1'])
            {
                rows[searchQueue[index].row][n - '1'] = true;
                columns[searchQueue[index].column][n - '1'] = true;
                grids[searchQueue[index].grid][n - '1'] = true;
                board[searchQueue[index].row][searchQueue[index].column] = n;
                if (search(index + 1, board))
                {
                    return true;
                }
                else
                {
                    rows[searchQueue[index].row][n - '1'] = false;
                    columns[searchQueue[index].column][n - '1'] = false;
                    grids[searchQueue[index].grid][n - '1'] = false;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board =
    {
        {'5','3','.','.','7','.','.','.','.'} ,
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution s;
    s.solveSudoku(board);
    cout << "te" << endl;
}