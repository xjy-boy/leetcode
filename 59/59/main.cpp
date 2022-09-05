#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    int dir[4][2] =
    {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    int border[4] = { 0,0,0,0 }; // {minR,maxR,minC,maxC}
    int change[4][4] =
    {
        {0,1},
        {3,-1},
        {1,-1},
        {2,1},
    };
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        for (int i = 0; i < n; i++)
        {
            matrix.push_back(vector<int>(n, 0));
        }
        border[1] = n-1;
        border[3] = n-1;
        int state = 0;
        int row = 0;
        int column = 0;
        for (int i = 0; i < n * n; i++)
        {
            matrix[row][column] = i + 1;
            int nextRow = row + dir[state][0];
            int nextColumn = column + dir[state][1];
            if (nextRow > border[1] || nextRow < border[0]
                || nextColumn > border[3] || nextColumn < border[2])
            {
                border[change[state][0]] += change[state][1];
                state = (state + 1) % 4;
                row += dir[state][0];
                column += dir[state][1];
            }
            else
            {
                row = nextRow;
                column = nextColumn;
            }
        }
        return matrix;
    }
};

int main()
{
    Solution s;
    s.generateMatrix(3);
}