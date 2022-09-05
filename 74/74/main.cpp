#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int column = matrix[0].size() - 1;
        while (row < matrix.size() && column >= 0)
        {
            if (target == matrix[row][column])
            {
                return true;
            }
            else if (target > matrix[row][column])
            {
                row += 1;
            }
            else
            {
                column -= 1;
            }
        }
        return false;
    }
};