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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        border[1] = matrix.size() - 1;
        border[3] = matrix[0].size() - 1;
        int state = 0;
        int row = 0;
        int column = 0;
        vector<int> ans;
        for (int i = 0; i < matrix.size() * matrix[0].size(); i++)
        {
            ans.emplace_back(matrix[row][column]);
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
        return ans;
    }
};