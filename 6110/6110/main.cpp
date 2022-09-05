#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<long>> path;
    int rows = 0;
    int columns = 0;
    int mod = 1e9 + 7;
    static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    long findPath(vector<vector<int>>& matrix, int row, int column) {
        if (path[row][column] != 0)
        {
            return path[row][column];
        }
        long result = 1;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dirs[i][0], newColumn = column + dirs[i][1];
            if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]) {
                result =( result + findPath(matrix, newRow, newColumn))% mod;
            }
        }

        path[row][column] = result;
        return result;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        path = vector<vector<long>>();
        rows = grid.size();
        columns = grid[0].size();
        for (int i = 0; i < rows; i++)
        {
            path.emplace_back(columns, 0);
        }

        long ans = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                long res = findPath(grid, i, j);
                ans = (ans + res) % mod;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> m = {
        {1,1},
        {3,4}
    };
    cout << s.countPaths(m) << endl;
}