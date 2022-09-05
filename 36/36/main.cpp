#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows = vector<unordered_set<char>>(9);
        unordered_set<char> columns;
        vector<unordered_set<char>> grid = vector<unordered_set<char>>(3);
        for (int i = 0; i < 9; i++)
        {
            columns.clear();
            if (i % 3 == 0)
            {
                grid[0].clear();
                grid[1].clear();
                grid[2].clear();
            }
            for (int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }

                if (rows[j].count(board[i][j]))
                {
                    return false;
                }
                else
                {
                    rows[j].insert(board[i][j]);
                }

                if (columns.count(board[i][j]))
                {
                    return false;
                }
                else
                {
                    columns.insert(board[i][j]);
                }

                int gridIndex = j / 3;
                if (grid[gridIndex].count(board[i][j]))
                {
                    return false;
                }
                else
                {
                    grid[gridIndex].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> boards =
        {   {'.', '.', '4', '.', '.', '.', '6', '3', '.'}, 
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
            {'5', '.', '.', '.', '.', '.', '.', '9', '.'}, 
            {'.', '.', '.', '5', '6', '.', '.', '.', '.'}, 
            {'4', '.', '3', '.', '.', '.', '.', '.', '1'}, 
            {'.', '.', '.', '7', '.', '.', '.', '.', '.'}, 
            {'.', '.', '.', '5', '.', '.', '.', '.', '.'}, 
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    Solution s;
    s.isValidSudoku(boards);
}