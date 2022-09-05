#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
        {
            return false;
        }
        int m = matrix[0].size();
        int row = 0;
        int column = m - 1;
        while(row < n && column >= 0)
        {
            if (matrix[row][column] == target)
            {
                return true;
            }
            else if (matrix[row][column] > target)
            {
                column -= 1;
            }
            else
            {
                row += 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15} ,
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    for (int i = 0; i < 32; i++)
    {
        cout << i << "\t" << s.findNumberIn2DArray(matrix, i) << endl;
    }

    //cout << s.findNumberIn2DArray(matrix, 3) << endl;
}