#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if (k >= m * n)
        {
            k -= m * n;
        }
        vector<vector<int>> ans = vector<vector<int>>(grid);
        int nextRow = 0;
        int nextColumn = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nextColumn = j + k;
                nextRow = i + nextColumn / n;
                nextColumn = nextColumn % n;
                nextRow = nextRow % m;
                ans[nextRow][nextColumn] = grid[i][j];
            }
        }
        return ans;
    }
};