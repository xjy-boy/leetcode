#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int row = 0;
        int column = 0;
        int m = mat.size();
        int n = mat[0].size();
        int rowC = -1;
        int columnC = 1;
        while (row < m  && column < n && row >= 0 && column >= 0)
        {
            while (row < m  && column < n && row >= 0 && column >= 0)
            {
                ans.emplace_back(mat[row][column]);
                row += rowC;
                column += columnC;
            }
            if (row == m && column < 0)
            {
                row = m - 1;
                column = 1;
            }
            else if (row < 0 && column == n)
            {
                row = 1;
                column = n - 1;
            }
            else if (row == m)
            {
                column += 2;
                row -= 1;
            }
            else if (row < 0)
            {
                row += 1;
            }
            else if (column == n)
            {
                column -= 1;
                row += 2;
            }
            else if (column < 0)
            {
                column += 1;
            }
            rowC = -rowC;
            columnC = -columnC;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    s.findDiagonalOrder(mat);
}