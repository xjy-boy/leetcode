#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        preSum.push_back(vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            preSum.push_back(vector<int>(n + 1, 0));
            for (int j = 0; j < n; j++)
            {
                preSum[i + 1][j + 1] =
                    preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1]
            - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {3,0,1,4,2} ,{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}
    };
    NumMatrix numMatrix = NumMatrix(matrix);
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
}